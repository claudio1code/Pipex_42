/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:55:18 by clados-s          #+#    #+#             */
/*   Updated: 2025/07/29 13:41:44 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_putdigit(long n, char *s, int index);
static int	count_digits(long n);

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	nbr = (long)n;
	len = count_digits(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}	
	recursive_putdigit(nbr, str, len - 1);
	return (str);
}

static int	count_digits(long n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	recursive_putdigit(long n, char *s, int index)
{
	if (n >= 10)
		recursive_putdigit(n / 10, s, index - 1);
	s[index] = (n % 10) + '0';
}
