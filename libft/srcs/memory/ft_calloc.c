/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:10:25 by clados-s          #+#    #+#             */
/*   Updated: 2025/07/30 10:06:32 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tt_size;

	if (nmemb && size && nmemb != (nmemb * size) / size)
		return (NULL);
	tt_size = nmemb * size;
	ptr = malloc(tt_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, tt_size);
	return (ptr);
}
