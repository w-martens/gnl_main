/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 19:26:29 by wmartens       #+#    #+#                */
/*   Updated: 2020/01/28 21:09:58 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

int			get_next_line(int fd, char **line);

int			nl_check(char *buf);
char		*joiner(char *res, char *buf);
char		*ft_strdup(const char *s1);
char		*ft_nldup(char *s1);
size_t		ft_strlen(const char *s);

#endif
