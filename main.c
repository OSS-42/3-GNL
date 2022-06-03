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
		free(nextline);
	}
	return (0);
}
