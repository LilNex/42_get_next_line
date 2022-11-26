/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:19:56 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/26 17:15:12 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	char		*t;
	int			n;
	if (!str)
		str = ft_calloc(BF_SIZE,sizeof(char));
	while (!ft_strchr(str,'\n'))
	{
		n =ft_strlen(str) + BF_SIZE + 1;
		tmp = ft_calloc(n,sizeof(char));
		t = ft_calloc(BF_SIZE + 1,sizeof(char));
		if(!read(fd,t,BF_SIZE))
			return NULL;
			// printf("str is : %s\n",t);
		t = ft_strjoin(str,t);
		free(str);
		str = ft_strdup(t);
		free(t);
	}
	t = ft_strcut(&str,'\n');
	// printf("inside ft: %s\n",str);
	// printf("len is : %d\n",len);
	// printf("str is : %s\n",t);
	return t;
}

// int main()
// {
// 	// printf("Hello World \n\n");
// 	// printf("Openning the file ...\n");
// 	int fd = open("file.txt", O_RDONLY);

// 	printf("the fd is : %d \n",fd);
// 	// printf("the default BUFFERSIZE is : %d\n",BF_SIZE);
// 	printf("line : %s",get_next_line(fd));
// 	printf("line : %s",get_next_line(fd));
// 	printf("line : %s",get_next_line(fd));
// 	printf("line : %s",get_next_line(fd));
// 	printf("line : %s",get_next_line(fd));
// 	printf("line : %s",get_next_line(fd));


// 	return (0);
// }

