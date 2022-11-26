/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:19:56 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/26 02:23:34 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void get_next_line(int fd)
{
	static char	*str;
	// int			len;

	// str = malloc(BF_SIZE + 1);
	// len = read(fd, str, BF_SIZE);
	// while (!ft_strchr(str,'\n'))
	// {
	// 	str = malloc(ft_strlen(str) + BF_SIZE + 1);
	// }
	if(!str)
		str = malloc(BF_SIZE + 1);
	char *c = load_file(str,fd);
	

	// printf("len is : %d\n",len);
	printf("str is : %s\n",c);

}

int main()
{
	// printf("Hello World \n\n");
	// printf("Openning the file ...\n");
	int fd = open("file.txt", O_RDONLY);

	printf("the fd is : %d \n",fd);
	// printf("the default BUFFERSIZE is : %d\n",BF_SIZE);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);


	return (0);
}

