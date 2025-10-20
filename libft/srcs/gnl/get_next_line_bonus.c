/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:27:29 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/07 15:00:17 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*free_null(void *ptr);
static char		*pickup_line(char *rest);
static char		*update_rest(char *rest);
static char		*ft_strjoin_and_free_rest(char *rest, char *buffer);

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bytes_buffer;
	static char	*rest[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	bytes_buffer = 1;
	while (!ft_strchr(rest[fd], '\n') && bytes_buffer > 0)
	{
		bytes_buffer = read(fd, buffer, BUFFER_SIZE);
		if (bytes_buffer == -1)
			return (free(buffer), rest[fd] = free_null(rest[fd]));
		buffer[bytes_buffer] = '\0';
		rest[fd] = ft_strjoin_and_free_rest(rest[fd], buffer);
		if (!rest[fd])
			return (NULL);
	}
	free(buffer);
	line = pickup_line(rest[fd]);
	rest[fd] = update_rest(rest[fd]);
	return (line);
}

static void	*free_null(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

static char	*pickup_line(char *rest)
{
	char	*new_line;
	int		i;

	if (!rest || *rest == '\0')
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	new_line = ft_calloc(sizeof(char), (i + 1));
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		new_line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
		new_line[i] = rest[i];
	return (new_line);
}

static char	*update_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
		return (free_null(rest));
	i++;
	new_rest = ft_calloc(sizeof(char), ft_strlen(rest) - i + 1);
	if (!new_rest)
		return (free_null(rest));
	j = 0;
	while (rest[i])
		new_rest[j++] = rest[i++];
	free(rest);
	return (new_rest);
}

static char	*ft_strjoin_and_free_rest(char *rest, char *buffer)
{
	char	*new_str;
	int		len_newstr;
	int		i;
	int		j;

	if (!rest)
		rest = ft_calloc(sizeof(char), 1);
	if (!buffer)
		return (rest);
	len_newstr = ft_strlen(rest) + ft_strlen(buffer);
	new_str = ft_calloc(sizeof(char), len_newstr + 1);
	if (!new_str)
		return (free_null(rest));
	i = -1;
	while (rest[++i])
		new_str[i] = rest[i];
	j = -1;
	while (buffer[++j])
		new_str[j + i] = buffer[j];
	free(rest);
	return (new_str);
}
