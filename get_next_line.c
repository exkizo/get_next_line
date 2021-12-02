/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrei <jocorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:52:17 by jocorrei          #+#    #+#             */
/*   Updated: 2021/12/02 15:30:50 by jocorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*clear_box(char	*str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!s)
		return (NULL);
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

char	*get_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*line;

	j = 0;
	if (*str == '\0')
		return (NULL);
	i = find_end_line(str);
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	while (i--)
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		line[j] = str[j];
		line[j + 1] = '\0';
	}
	else
		line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*fd_box[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_box[fd] = read_line(fd, fd_box[fd]);
	if (!fd_box[fd])
	{
		free(fd_box[fd]);
		return (NULL);
	}	
	line = get_line(fd_box[fd]);
	fd_box[fd] = clear_box(fd_box[fd]);
	return (line);
}
