/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:17:12 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/13 14:10:03 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>

typedef struct s_pipex
{
	char	**cmd1_args;
	char	**cmd2_args;
	char	*infile;
	char	*outfile;
}t_pipex;

void	init_data(t_pipex *data, int argc, char **argv);
int		main(int argc, char **argv, char **envp);
void	child_one_process(t_pipex *data, int *pipe_fd, char **envp);
void	child_two_process(t_pipex *data, int *pipe_fd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
void	parents_process(t_pipex *data, int *pipe_fd, char **envp);
void	*free_data(t_pipex *data);
#endif