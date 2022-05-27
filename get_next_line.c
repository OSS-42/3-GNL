/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:53:40 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/25 10:53:40 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char					*s1;
	char					*buffer;
	unsigned long			nexteol;
	unsigned long			nextstart;

	fd = open("numbers.dict", O_RDONLY);
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || fd == -1)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);





	
	nexteol = ft_strchr(buffer);
	if (nexteol == 0)
		return (NULL);
	printf("Next EOL : %ld\n", nexteol);
	nextstart = 0 ;
	s1 = ft_substr(buffer, nextstart, nexteol + 1);
	close(fd);
	free(buffer);
	return (s1);
}

int	main()
{
	int	fd;

	fd = open("numbers.dict", O_RDONLY);
	while(1)
	{
		char *nextline = get_next_line(fd);
		if (nextline == NULL)
			break ;
		printf("test : %s\n", nextline);
	}

	return (0);
}

/*int	main()
{
	int	fd;
	int	fd2;

	fd = open("numbers.dict", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	while(1)
	{
		char *nextline = get_next_line(fd);
		char *nextline2 = get_next_line(fd2);
		printf("test : %s\n", nextline);
		printf("test : %s\n", nextline2);
		if (nextline == NULL || nextline2 == NULL)
			break ;
	}

	return (0);
}*/