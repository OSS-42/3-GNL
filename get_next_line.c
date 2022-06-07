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

char	*ft_clean(char *fixedbuffer, size_t pos)
{
	char	*temp;
	size_t	i;
	size_t	len;

	i = 0;
	temp = ft_calloc(pos, 1);
	if (!temp)
		return (NULL);
	while (fixedbuffer[pos])
		temp[i++] = fixedbuffer[pos++];
	temp[i] = '\0';
	len = ft_strlen(temp);
	fixedbuffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!fixedbuffer)
		return (NULL);
	i = -1;
	while (temp[++i])
		fixedbuffer[i] = temp[i];
	fixedbuffer[i] = '\0';
	free (temp);
	return (fixedbuffer);
}

char	*ft_line(char *string, size_t len, int flag)
{
	char	*linetoprint;
	long	pos;

	linetoprint = (char *)malloc(sizeof(char) * (len + 1));
	if (!linetoprint)
		return (NULL);
	pos = 0;
	while (string[pos])
	{
		if (string[pos] == '\n')
			break ;
		linetoprint[pos] = string[pos];
		pos++;
	}
	if (flag != 0)
	{
		linetoprint[pos] = '\n';
		pos = pos + 1;
	}
	linetoprint[pos] = '\0';
	return (linetoprint);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*fixedbuffer;
	char			*linetoprint;
	size_t			i;
	size_t			bytesread;
	int				flag;

	flag = 1;
	i = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || fd == -1 || read(fd, 0, 0) < 0)
		return (NULL);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread == 0 && i == 0 && fixedbuffer[0] == '\0')
		return (NULL);
	while (bytesread > 0)
	{
		fixedbuffer = ft_strjoin(fixedbuffer, buffer);
		i = ft_strchr(fixedbuffer);
		if (i > 0)
			break ;
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	if (fixedbuffer != NULL && i == 0)
		flag = 0;
	i = ft_strlen(fixedbuffer);
	linetoprint = ft_line(fixedbuffer, i, flag);
	fixedbuffer = ft_clean(fixedbuffer, i + 1);
	free (buffer);
	return (linetoprint);
}
