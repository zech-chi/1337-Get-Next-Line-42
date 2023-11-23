/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:35:04 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/23 16:10:48 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			r;
	int			e;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	line = NULL;
	if (has_the_end(buff[fd], &line))
		return (line);
	r = read(fd, buff[fd], BUFFER_SIZE);
	e = has_the_end(buff[fd], &line);
	while (r > 0 && e == 0)
	{
		r = read(fd, buff[fd], BUFFER_SIZE);
		e = has_the_end(buff[fd], &line);
	}
	if (r == -1 || e == -1 || (line && ft_strlen(line) == 0))
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
