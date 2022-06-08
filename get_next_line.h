/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:53:38 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/25 10:53:38 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct s_parameters
{
	size_t		eolpos;
	size_t		lenstr;
	size_t		bytesread;
	int		flag;
}	t_parameters;

char	*get_next_line(int fd);
size_t	ft_strlen(char *string);
size_t	ft_strchr(char *string);
char	*ft_clean(char *fixedbuffer, t_parameters *table);
char	*ft_line(char *string, t_parameters *table);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *fixedbuffer, char *buffer, t_parameters *table);

#endif