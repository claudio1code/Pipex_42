/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:30:02 by clados-s          #+#    #+#             */
/*   Updated: 2025/07/29 09:52:20 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substrlen(const char *str, char c);
static char		**fill_array(char const *s, char c, char **new_str);
static size_t	count_words(const char *s, char c);
static void		ft_free_split(char **str_array);

char	**ft_split(char const *s, char c)
{
	char	**new_str;

	if (!s)
		return (NULL);
	new_str = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!new_str)
		return (NULL);
	new_str = fill_array(s, c, new_str);
	return (new_str);
}

static size_t	ft_substrlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**fill_array(char const *s, char c, char **new_str)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
		s++;
		if (*s != c && *s)
		{
			i = 0;
			new_str[j] = ft_calloc(ft_substrlen(s, c) + 1, sizeof(char));
			if (!new_str[j])
			{
				ft_free_split(new_str);
				return (0);
			}
			while (*s && *s != c)
				new_str[j][i++] = *s++;
			j++;
		}
	}
	new_str[j] = NULL;
	return (new_str);
}

static size_t	count_words(const char *s, char c)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			++word;
	}
	return (word);
}

static void	ft_free_split(char **str_array)
{
	int	i;

	i = -1;
	while (str_array[++i])
		free(str_array[i]);
	free(str_array);
}
