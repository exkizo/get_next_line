/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrei <jocorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:52:09 by jocorrei          #+#    #+#             */
/*   Updated: 2021/12/08 15:44:00 by jocorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int				i;
	int				j;
	char			*new;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		*s1 = '\0';
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new[i + j] = s2[j];
	new[i + j] = '\0';
	free(s1);
	return (new);
}

int	check_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n' || s[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *fd_box)
{
	int		count;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	count = 1;
	while (!check_line(fd_box) && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[count] = '\0';
		fd_box = ft_strjoin(fd_box, buff);
	}
	free(buff);
	return (fd_box);
}

int	find_end_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}
