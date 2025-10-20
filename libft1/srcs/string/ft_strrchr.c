/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:59:10 by clados-s          #+#    #+#             */
/*   Updated: 2025/07/28 11:49:41 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	i = ft_strlen(s);
	str = (unsigned char *)s;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		--i;
	}
	return (NULL);
}
