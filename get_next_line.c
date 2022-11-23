/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:19:56 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/14 12:42:48 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>

void get_next_line(int fd)
{
	char	*str;
	int		len;

	str = malloc(BF_SIZE + 1);
	len = read(fd, str, BF_SIZE);

	printf("len is : %d\n",len);
	printf("str is : %s",str);

}

int main()
{
	printf("Hello World \n\n");
	// printf("Openning the file ...\n");
	int fd = open("file.txt", O_RDONLY);

	printf("the fd is : %d \n",fd);
	printf("the default BUFFERSIZE is : %d\n",BF_SIZE);
	get_next_line(fd);


	return (0);
}

