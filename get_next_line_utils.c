/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:15:12 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/27 12:27:38 by ichaiq           ###   ########.fr       */
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
	while (--c > 0)
		*((char *)(ptr + c)) = '\0';
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
	if (!str)
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
char	*ft_strdup(const char *s1)
{
	char	*new;
	int		len;

	len = ft_strlen((const char *)s1);
	new = ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (NULL);
	if (len == 0)
	{
		*new = '\0';
		return (new);
	}
	while (*s1)
		*new++ = *s1++;
	*new = '\0';
	return (new - len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= (unsigned int) strlen)
		return ((char *)ft_strdup("\0"));
	if ((size_t)strlen > len)
		strlen = len;
	str = ft_calloc(strlen + 1, sizeof(char));
	if (!str)
		return (NULL);
	s += start;
	i = 0;
	while (*s && len-- > 0)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
char *ft_strcut(char **s,char c, int *last)
{
	char	*pos;
	int		len;
	char 	*str;
	int		i;

	i = 0;
	pos = ft_strchr(*s, c);

	if (!*s && (!pos))
		return (*s);
	if(pos)
		len = pos - *s;
	else
		len = ft_strlen(*s);

	str = ft_calloc(len, sizeof(char));
	while ((*s)[i] != c && str)
	{
		str[i] = (*s)[i];
		// printf("%d | cut s : %s\n",i, str);
		if ((*s)[i + 1] == c)
		{
			str[i + 1] = (*s)[i + 1];
			i++;
			break;
		}

		else if ((*s)[i + 1] == '\0')
		{
			str[i + 1] = '\0';
			break;
		}
		i++;
	}
	if(!*last)  
		*s = ft_substr((*s),len + 1,ft_strlen((*s)) - len);
	else *s = 0;

	return (str);
}

// char *load_file(char *str, int fd)
// {
// 	static char	*tmp;
// 	char	*t;
// 	int			n;

// 	if(!tmp)
// 		tmp = malloc(BF_SIZE + 1);

// 	while (!ft_strchr(tmp,'\n'))
// 	{
// 		n = ft_strlen(tmp) + BF_SIZE + 1;

// 		t = ft_calloc(n, sizeof(char));
		
		
// 		if(read(fd, t, BF_SIZE) == 0)
// 			return ft_strjoin(tmp,str);
// 		tmp = ft_strjoin(tmp,t);
		
// 	}
// 	free(t);
// 	t = ft_strcut(tmp,'\n');

// 	return t;
// }