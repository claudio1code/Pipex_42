/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:59:24 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/08 15:56:10 by clados-s         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_pipex	data;
	int		pipe_fd[2];
	

	if (argc != 5)
	{
		ft_printf("Uso: ./pipex cmd1 cmd2 outfile\n");
		return (1);
	}
	init_data(&data, argc, argv);
	pipe(pipe_fd[2]);
	if (pipe_fd[2] == -1)
		return (0);
	fork()
}
