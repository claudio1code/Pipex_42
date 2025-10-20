/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freenull_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:10:25 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/14 10:58:22 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_split_null(char **str_array)
{
	int	i;

	i = 0;
	if (!str_array)
		return (NULL);
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
	return (NULL);
}
