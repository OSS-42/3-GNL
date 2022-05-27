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

size_t	ft_strlen(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

size_t	ft_strchr(char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (i);
	}
	return (0);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	slen1 = ft_strlen((char *)s1);
	slen2 = ft_strlen((char *)s2);
	dst = (char *)malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < slen1)
	{
		dst[i] = s1[i];
	}
	j = -1;
	while (++j < slen2)
	{
		dst[i + j] = s2[j];
	}
	dst[i + j] = '\0';
	return (dst);
}

size_t	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
