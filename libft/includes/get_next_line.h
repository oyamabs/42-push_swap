/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:08:13 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/13 14:58:40 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

char	*get_next_line(int fd);
char	*_ft_strchr(const char *s, int c);
void	*_ft_memcpy(void *dest, const void *src, size_t n);
size_t	_ft_strlen(const char *s);
void	_ft_strcat(char **dst_ptr, const char *src);

#endif
