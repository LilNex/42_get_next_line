/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:15:12 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/25 00:07:41 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void*		ptr;
	int		c;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = count;
	}
	c = count * size;
	ptr = malloc(c);
	if (!ptr)
		return (NULL);
	while (--c >= 0)
		*(char*)&ptr[c] = 0;
	return ((void *)ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	*adress;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (c % 256))
		{
			adress = (unsigned char *)&s[i];
			return ((char *)(adress));
		}
		i++;
	}
	if (s[i] == (c % 256))
		return ((char *) &s[i]);
	return ((char *) '\0');
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;

	i = (unsigned long)len -1;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	str = ft_calloc(size, sizeof(char));
	if (str == '\0')
		return (str);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

void *ft_realloc(void *ptr, size_t n)
{
	free(ptr);
	ptr = ft_calloc(n,1);
	return (ptr);
}

char *load_file(char *str, int fd)
{
	 char	*tmp;
	 int	n;

	while (!ft_strchr(str,'\n'))
	{
		n = ft_strlen(str) + BF_SIZE + 1;
		tmp = ft_calloc(n, sizeof(char));
		ft_memmove(tmp,str,ft_strlen(str));
		str = ft_realloc(str,n);
		if(read(fd, str, BF_SIZE) == 0)
			return ft_strjoin(tmp,str);
		str = ft_strjoin(tmp,str);
		free(tmp);
	}
	return str;
}

// char *get_line(char *str)
