/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:44:31 by clados-s          #+#    #+#             */
/*   Updated: 2025/07/21 16:43:43 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen((char *)src);
	if (size == 0)
		return ((size_t)src_len);
	i = -1;
	while (++i < (size - 1) && src[i])
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return ((size_t)src_len);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int main()
// {
// 	char src[] = "coucou";
// 	char dest[10]; memset(dest, 'A', 10);
// 	ft_strlcpy(dest, src, -1);
// }
