/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:14:01 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/13 17:03:53 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **str_array)
{
	int	i;

	i = -1;
	if (!str_array)
		return ;
	while (str_array[++i])
		free(str_array[i]);
	free(str_array);
}
