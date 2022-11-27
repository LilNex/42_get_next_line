/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:05:25 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/27 12:25:03 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>

# define UPHEX "0123456789ABCDEF"
# define LOWHEX "0123456789abcdef"
# define DEC "0123456789"

# ifdef BUFFER_SIZE
    # define BF_SIZE BUFFER_SIZE
#else 
    # define BF_SIZE BUFSIZ
#endif

size_t  ft_strlen(const char *c);
char    *ft_strchr(const char *s, int c);
// void    *ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char    *load_file(char *str, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strcut(char **s, char c, int *last);
char    *get_next_line(int fd);

#endif
