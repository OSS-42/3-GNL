/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:53:34 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/25 10:53:34 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < len)
		len = slen;
	if (slen <= start)
		len = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	if (slen <= start)
	{
		dst[i] = '\0';
		return (dst);
	}
	i = -1;
	while (s[start + ++i] && i< len)
		dst[i] = s[start + i];
	dst[i] = '\0';
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	int		n;

	n = (count * size);
	buffer = malloc(n);
	if(buffer)
		while(n > 0)
			((char *)buffer)[--n] = 0;
	return (buffer);
}

char	*ft_strjoin(char *fixedbuffer, char *buffer)
{
	size_t	slen1;
	size_t	slen2;
	char	*dst;
	size_t	i;
	size_t	j;

	slen1 = ft_strlen((char *)fixedbuffer);
	slen2 = 5;
	dst = (char *)malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < slen1)
	{
		dst[i] = fixedbuffer[i];
	}
	j = -1;
	while (++j < slen2)
	{
		dst[i + j] = buffer[j];
	}
	dst[i + j] = '\0';
	return (dst);
}
