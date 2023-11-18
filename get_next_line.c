/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:24:12 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/18 16:13:34 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_the_end(char *buff)
{
	size_t	index;

	index = 0;
	while (index <= BUFFER_SIZE)
	{
		if (buff[index] == '\n' || buff[index] == '\0')
			return (index);
		index++;
	}
	return (-1);
}

void	ShiftAfterNewLine(char *buff, int end)
{
	size_t	i;

	i = 0;
	while (end <= BUFFER_SIZE)
		buff[i++] = buff[end++];
	while (i <= BUFFER_SIZE)
		buff[i++] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char	*line;
	char	*BeforeNewLine;
	size_t	end_line_index;
	size_t	i;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	
	while (read(fd, buff, BUFFER_SIZE) > 0 && has_the_end(buff) == -1)
		line = ft_strjoin(line, ft_strdup(buff));
	end_line_index = has_the_end(buff);
	BeforeNewLine = malloc(end_line_index + 1 + 1);
	if (!BeforeNewLine)
		return (NULL);
	i = -1;
	while (++i < end_line_index)
		BeforeNewLine[i] = buff[i];
	BeforeNewLine[i++] = '\n';
	BeforeNewLine[i] = '\0';
	line = ft_strjoin(line, BeforeNewLine);
	ShiftAfterNewLine(buff, end_line_index + 1);
	return (line);
}
