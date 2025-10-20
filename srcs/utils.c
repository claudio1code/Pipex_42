/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:00:37 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/17 14:45:07 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	error_exit(char *msg, t_pipex *data)
{
	perror(msg);
	if (data->cmd1_args)
		free_split(data->cmd1_args);
	if (data->cmd2_args)
		free_split(data->cmd2_args);
	exit(1);
}

void	execute_command(char **cmds_args, char **envp)
{
	char	*cmd_path;

	cmd_path = get_cmd_path(cmds_args[0], envp);
	if (!cmd_path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmds_args[0], 2);
		ft_putstr_fd("\n", 2);
		perror("pipex: command not found");
		exit(127);
	}
	execve(cmd_path, cmds_args, envp);
	free(cmd_path);
	perror("pipex");
	exit(1);
}
