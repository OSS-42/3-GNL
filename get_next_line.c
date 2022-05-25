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

#include <get_next_line.h>

char	*get_next_line(int fd)
{
	int						fd;
	char					*s1;
	char					*s2[9999];
	unsigned long			nexteol;
	unsigned long			nextstart;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (NULL);
	read(fd, s2, 9999);
	nexteol = ft_strchr(s2);
	printf("Next EOL : %d\n", nexteol);
	nextstart = ft_next_start(nexteol);
	s1 = ft_substr(s2, nextstart, nexteol);



	close(fd);
}
