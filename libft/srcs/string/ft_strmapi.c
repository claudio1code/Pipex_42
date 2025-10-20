/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:13:17 by clados-s          #+#    #+#             */
/*   Updated: 2025/07/30 13:48:10 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s_new;

	if (!s || !f)
		return (NULL);
	i = -1;
	s_new = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!s_new)
		return (NULL);
	while (s[++i])
		s_new[i] = f(i, s[i]);
	return (s_new);
}
