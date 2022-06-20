/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 08:40:09 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/30 08:40:09 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int	main()
{
	int	fd;
	int	fd2;
	clock_t t;

    t = clock();
	fd = open("numbers.dict", O_RDONLY);
	fd2 = open("numbers2.txt", O_RDONLY);
	while(1)
	{
		char *nextline = get_next_line(fd);
		char *nextline2 = get_next_line(fd2);
		printf("%s", nextline);
		printf("%s", nextline2);
		if (nextline == NULL || nextline2 == NULL)
			break ;
	}
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\n|get_next_line took %f seconds to read all the fd|\n", time_taken);
	return (0);
}
