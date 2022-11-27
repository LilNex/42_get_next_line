/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:19:56 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/27 12:29:42 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*str;
	static int	last;
	char		*t;

	last = 0;
	if (!str && !last)
		str = ft_calloc(BF_SIZE,sizeof(char));
	while (!ft_strchr(str,'\n') && str)
	{
		t = ft_calloc(BF_SIZE + 1,sizeof(char));

		if(!read(fd, t, BF_SIZE))
		{
			if(last)
				return NULL;
			else
				last = 1;
		}
		if(!last)
			t = ft_strjoin(str,t);
		free(str);
		str = ft_strdup(t);
		free(t);
		if(last) break;
	}
	t = ft_strcut(&str,'\n',&last);
	if(last) free(str);

	return t;

}
int main()
{
	// printf("Hello World \n\n");
	// printf("Openning the file ...\n");
	int fd = open("file.txt", O_RDONLY);

	printf("the fd is : %d \n",fd);
	// printf("the default BUFFERSIZE is : %d\n",BF_SIZE);
	printf("line : %s",get_next_line(fd));
	printf("line : %s",get_next_line(fd));
	printf("line : %s",get_next_line(fd));
	printf("line : %s",get_next_line(fd));
	printf("line : %s",get_next_line(fd));
	printf("line : %s",get_next_line(fd));


	return (0);
}


