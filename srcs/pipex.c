/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:59:24 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/09 16:37:16 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_pipex *data, int argc, char **argv)
{
	data->infile = argv[1];
	data->outfile = argv[4];
	data->cmd1_args = ft_split(argv[2], ' ');
	data->cmd2_args = ft_split(argv[3], ' ');
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		pipe_fd[2];
	pid_t	pid1;

	if (argc != 5)
	{
		ft_printf("Uso: ./pipex cmd1 cmd2 outfile\n");
		return (1);
	}
	init_data(&data, argc, argv);
	if (pipe(pipe_fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return (1);
	if (pid1 == 0)
		child_one_process(&data, pipe_fd, envp);
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
	execve(cmd_path, data->cmd1_args, *envp);
	perror("pipex: comando não encontrado");
	exit(127);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_part;
	char	*full_path;
	int		i;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_part = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path_part, cmd);
		free (path_part);
		if (access(full_path, X_OK) == 0)
		{
			free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (free_split_null(paths));
}
