/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:59:24 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/13 15:45:37 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_pipex *data, int argc, char **argv)
{
	(void)argc;
	data->infile = argv[1];
	data->outfile = argv[4];
	data->cmd1_args = ft_split(argv[2], ' ');
	data->cmd2_args = ft_split(argv[3], ' ');
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		pipe_fd[2];

	if (argc != 5)
	{
		ft_printf("Uso: ./pipex cmd1 cmd2 outfile\n");
		return (1);
	}
	init_data(&data, argc, argv);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipex: pipe");
		return (1);
	}
	parents_process(&data, pipe_fd, envp);
	free_split(data.cmd1_args);
	free_split(data.cmd2_args);
	return (0);
}

void	child_one_process(t_pipex *data, int *pipe_fd, char **envp)
{
	int		infile_fd;
	char	*cmd_path;

	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close (pipe_fd[1]);
	infile_fd = open(data->infile, O_RDONLY);
	if (infile_fd == -1)
	{
		perror("pipex: infile");
		exit(1);
	}
	dup2(infile_fd, STDIN_FILENO);
	close (infile_fd);
	cmd_path = get_cmd_path(data->cmd1_args[0], envp);
	execve(cmd_path, data->cmd1_args, envp);
	perror("pipex: comando não encontrado");
	free(cmd_path);
	exit(127);
}

void	child_two_process(t_pipex *data, int *pipe_fd, char **envp)
{
	int		outfile_fd;
	char	*cmd_path;

	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		perror("pipex: outfile");
		exit(1);
	}
	dup2(outfile_fd, STDOUT_FILENO);
	close (outfile_fd);
	cmd_path = get_cmd_path(data->cmd2_args[0], envp);
	execve(cmd_path, data->cmd2_args, envp);
	perror("pipex: comando não encontrado");
	free(cmd_path);
	exit(127);
}


