/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:27:45 by clados-s          #+#    #+#             */
/*   Updated: 2025/07/21 14:28:00 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s_ptr;
	unsigned char		*d_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	s_ptr = (const unsigned char *)src;
	d_ptr = (unsigned char *)dest;
	while (n > 0)
	{
		*d_ptr = *s_ptr;
		d_ptr++;
		s_ptr++;
		n--;
	}
	return (dest);
}
