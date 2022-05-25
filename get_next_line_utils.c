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

#include <get_next_line.h>

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
	size_t	len;

	i = -1;
	while (s[i++])
		if (s[i] == '\n')
			return (i);
	return (NULL);
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
	return (dst)
}

size_t	ft_next_start(size_t nexteol)
{
	static unsigned long	start;
	static unsigned long	count;

	count = 0;
	if (count == 0)
		start = 0;
	else
		start = nexteol + 1;
}