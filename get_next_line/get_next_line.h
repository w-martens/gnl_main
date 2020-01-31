/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 19:26:29 by wmartens       #+#    #+#                */
/*   Updated: 2020/01/30 17:32:01 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int			get_next_line(int fd, char **line);
int			nl_check(char *str);
char		*free_str(char *str1);
char		*joiner(char *str1, char *str2);
size_t		ft_strlen(const char *s);
char		*ft_nldup(char *s1);

#endif
