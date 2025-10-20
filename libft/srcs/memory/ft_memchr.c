/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:10:07 by clados-s          #+#    #+#             */
/*   Updated: 2025/07/22 15:15:08 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	find_c;

	str = (unsigned char *)s;
	find_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == find_c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
