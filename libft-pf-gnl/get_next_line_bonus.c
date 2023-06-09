/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:54:47 by macastan          #+#    #+#             */
/*   Updated: 2022/12/05 14:54:53 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *rest)
{
	char	*buffer;
	int		read_bytes;

	buffer = ft_calloc2((BUFFER_SIZE + 1), sizeof(char));
	read_bytes = 1;
	while (!ft_strchr2(rest, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(rest);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		rest = ft_joinandfree(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*ft_get_line(char *rest)
{
	char	*line;
	int		i;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = ft_calloc2((i + 2), sizeof(char));
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_rest(char *rest)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	str = ft_calloc2((ft_strlen2(rest) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (rest[i])
	{
		str[j] = rest[i];
		j++;
		i++;
	}
	free(rest);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = ft_read(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = ft_get_line(rest[fd]);
	rest[fd] = ft_rest(rest[fd]);
	return (line);
}
