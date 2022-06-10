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

char	*ft_clean(char *fixedbuffer, t_parameters *table)
{
	char	*temp;
	size_t	templen;
	size_t	i;
	size_t	j;

	templen = table->lenstr - (table->eolpos);
	temp = (char *)malloc(sizeof(char) * (templen + 1));
	if (!temp)
		return (NULL);
	i = 0;
	j = table->eolpos;
	while (fixedbuffer[j])
		temp[i++] = fixedbuffer[j++];
	temp[i] = '\0';
	fixedbuffer = (char *)malloc(sizeof(char) * (templen + 1));
	if (!fixedbuffer || temp[0] == '\0')
	{
		free (temp);
		return (NULL);
	}
	i = -1;
	while (temp[++i])
		fixedbuffer[i] = temp[i];
	fixedbuffer[i] = '\0';
	free (temp);
	return (fixedbuffer);
}

char	*ft_line(char *string, t_parameters *table)
{
	char	*linetoprint;
	long	pos;

	linetoprint = (char *)malloc(sizeof(char) * (table->lenstr + 1));
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
	if (table->flag == 0)
	{
		linetoprint[pos] = '\n';
		pos = pos + 1;
	}
	linetoprint[pos] = '\0';
	table->eolpos = pos;
	return (linetoprint);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*fixedbuffer;
	char			*linetoprint;
	t_parameters	*table;

	table = ft_calloc(sizeof(t_parameters), 1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || fd == -1 || read(fd, 0, 0) < 0)
	{
		free (buffer);
		free (table);
		return (NULL);
	}
	table->bytesread = read(fd, buffer, BUFFER_SIZE);
	if (table->bytesread == 0 && fixedbuffer == NULL)
	{
		free (buffer);
		free (table);
		return (NULL);
	}
	table->lenstr = ft_strlen(fixedbuffer, table);
	while (table->bytesread > 0)
	{
		fixedbuffer = ft_strjoin(fixedbuffer, buffer, table);
		if (table->eolpos > 0)
			break ;
		if (fixedbuffer[0] == '\n')
			break ;
		table->bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	ft_strlen(fixedbuffer, table);
	if (fixedbuffer != NULL && table->eolpos == 0 && table->lenstr > 0 && table->bytesread == 0)
		table->flag = 1;
	linetoprint = ft_line(fixedbuffer, table);
	fixedbuffer = ft_clean(fixedbuffer, table);
	free (table);
	free (buffer);
	return (linetoprint);
}
