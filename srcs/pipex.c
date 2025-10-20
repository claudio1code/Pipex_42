/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:59:24 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/16 12:04:34 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_data(t_pipex *data, char **argv)
{
	data->infile = argv[1];
	data->outfile = argv[4];
	data->cmd1_args = ft_split(argv[2], ' ');
	data->cmd2_args = ft_split(argv[3], ' ');
}

static void	child_one_process(t_pipex *data, int *pipe_fd, char **envp)
{
	int		infile_fd;

	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close (pipe_fd[1]);
	infile_fd = open(data->infile, O_RDONLY);
	if (infile_fd == -1)
		error_exit("pipex: infile", data);
	dup2(infile_fd, STDIN_FILENO);
	close (infile_fd);
	execute_command(data->cmd1_args, envp);
}

static void	child_two_process(t_pipex *data, int *pipe_fd, char **envp)
{
	int		outfile_fd;

	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		error_exit("pipex: outfile", data);
	dup2(outfile_fd, STDOUT_FILENO);
	close (outfile_fd);
	execute_command(data->cmd2_args, envp);
}

static void	parent_process(t_pipex *data, int *pipe_fd, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("pipex: fork");
		return ;
	}
	if (pid1 == 0)
		child_one_process(data, pipe_fd, envp);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("pipex: fork");
		return ;
	}
	if (pid2 == 0)
		child_two_process(data, pipe_fd, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		pipe_fd[2];

	if (argc != 5)
	{
		ft_putstr_fd("parse error near `\n'", 2);
		return (1);
	}
	ft_bzero(&data, sizeof(t_pipex));
	init_data(&data, argv);
	if (pipe(pipe_fd) == -1)
		error_exit("pipex: pipe", &data);
	parent_process(&data, pipe_fd, envp);
	free_split(data.cmd1_args);
	free_split(data.cmd2_args);
	return (0);
}
