/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:59:24 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/08 12:01:06 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_pipex *data, int argc, char **argv)
{
	data->infile = argv[1];
	data->outfile = argv[4];
	data->cmd1_args = argv[2];
	data->cmd1_args = argv[3];
}

int	main(int argc, char **argv)
{
	
}


