/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:05:25 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/26 00:32:22 by ichaiq           ###   ########.fr       */
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


#endif
