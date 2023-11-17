/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:28:17 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/17 18:10:43 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	find_the_end(char *buff, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buff[i] == '\n' || buff[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

void	shift(char *buff, int index, int size)
{
	int j;
	int i;

	j = index + 1;
	i = 0;
	while (j < size)
		buff[i++] = buff[j++];
	
	while (i < size)
		buff[i++] = 0;
}

char	*get_next_line(int fd)
{
	static char	buff[ 1 + 1];
	char *line;
	int index;
	int i = 0;
	char *first_part;

	line = NULL;
	line = ft_strdup(buff);
	while (read(fd, buff,  1) && find_the_end(buff,  1) == -1)
		line = ft_strjoin(line, ft_strdup(buff));
	index = find_the_end(buff,  1);
	// get the first part
	first_part = malloc(index + 1);
	while (i < index)
	{
		first_part[i] = buff[i];
		i++;
	}
	buff[i] = 0;
	first_part[i] = '\n';
	first_part[i + 1] = '\0';
	line = ft_strjoin(line, first_part);
	
	shift(buff, index,  1 + 1);
	return (line);
}
