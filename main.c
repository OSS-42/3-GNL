/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 08:39:39 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/30 08:39:39 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	clock_t t;

    t = clock();
	fd = open("numbers.dict", O_RDONLY);
	while(1)
	{
		char *nextline = get_next_line(fd);
		if (nextline == NULL)
			break ;
		printf("%s", nextline);
		free(nextline);
	}
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\033[1;91m"); 
	printf("###END OF FILE###\n"); 
	printf("\033[0m");
	printf("\033[0;95m"); 
	printf("|get_next_line took %f seconds to read all the fd|\n", time_taken);
	printf("\033[0m");
	return (0);
}
/*
{
	int	fd;

	fd = open("numbers.dict", O_RDONLY);
	while(fd)
	{
		char *nextline = get_next_line(fd);
		printf("%s", nextline);
		free(nextline);
	}
	return (0);
}
*/
