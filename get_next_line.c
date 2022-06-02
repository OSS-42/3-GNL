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

	//1. copy buffer dans fixedbuffer
	//2. check dans fixedbuffer if \n
	//2a. si non, read again
	//3. si oui, copy string jusque \n dans dest
	//4. affiche dest, clean dest
	//5. clean fixedbuffer en enlevant la partie copiee dans dest

void	ft_clean(char *string, size_t pos)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = NULL;
	while(string[++pos])
		temp[i++] = string[pos];
	free (string);
	i = 0;
	string[i] = temp[i];
	free (temp);
}

size_t	ft_strlen(char *string)
{
	size_t	len;

	len = 0;
	while (string[len])
		len++;
	return (len);
}

char	*ft_line(char *string)
{
	char	*dest;
	long	len;
	long	pos;

	len = ft_strlen(string);
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	pos = -1;
	while(string[++pos])
		dest[pos] = string[pos];
	dest[pos]= '\0';
	ft_clean(string, pos);
	return (dest);
}

size_t	ft_strchr(char *string)
{
	size_t	i;

	i = 0;
	printf ("fixedbuffer : %s", string);
	while (string[i])
	{
		if (string[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char					*buffer;
	static char				*fixedbuffer;

	printf("all good so far %d", 1);
	fd = open("numbers.dict", O_RDONLY);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || fd == -1 || read(fd, buffer, 0) < 0)
		return (NULL);
	while (read(fd, buffer, 5) > 0)
	{
		printf("all good so far %d", 2);;
		fixedbuffer = ft_strjoin(fixedbuffer, buffer);
		if (ft_strchr(fixedbuffer) == 1)
		{
			printf("all good so far %d", 3);;
			return (ft_line(fixedbuffer));
		}
	}
	close (fd);
	free (buffer);
	return (NULL);
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