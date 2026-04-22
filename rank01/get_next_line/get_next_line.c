/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:04:51 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/22 12:23:58 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_return(char *buf, char *storage)
{
	free(buf);
	free(storage);
	return (NULL);
}

static char	*read_and_store(int fd, char *storage)
{
	int		bytes_read;
	char	*buffer;

	if (!storage)
		storage = ft_strdup("");
	if (!storage)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(storage), NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_return(buffer, storage));
		if (bytes_read == 0 && ft_strlen(storage) == 0)
			return (free_and_return(buffer, storage));
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (free_and_return(buffer, NULL));
	}
	free(buffer);
	return (storage);
}

static char	*extract_line(char *storage)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!storage || !storage[0])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		line = ft_substr(storage, 0, i + 1);
	else
		line = ft_substr(storage, 0, i);
	return (line);
}

static char	*update_storage(char *storage)
{
	char	*new_storage;
	size_t	index;

	index = 0;
	while (storage[index] && storage[index] != '\n')
		index++;
	if (!storage[index])
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_substr(storage, index + 1, ft_strlen(storage) - index - 1);
	free(storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_and_store(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	storage = update_storage(storage);
	return (line);
}
