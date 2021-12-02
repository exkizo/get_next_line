/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrei <jocorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:52:23 by jocorrei          #+#    #+#             */
/*   Updated: 2021/12/02 15:47:10 by jocorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *fd_box);
int		find_end_line(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
int		check_line(char *s);
char	*get_line(char *str);
char	*clear_box(char	*str);

#endif
