/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:36:27 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/20 22:26:43 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	shift_it(char	*buff, size_t j)
{
	size_t	i;

	i = 0;
	while (j < BUFFER_SIZE)
		buff[i++] = buff[j++];
	while (i < BUFFER_SIZE)
		buff[i++] = 0;
}

// 1 line has been completed
// 0 line hasn't been completed
int	has_the_end(char *buff, char *line)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == '\n' || buff[i] == '\0')
			break;
		i++;
	}
	if (i == BUFFER_SIZE || buff[i] == '\0')
	{
		line = ft_strjoin(line, ft_strdup(buff));
		shift_it(buff, BUFFER_SIZE);
		return (0);
	}
	temp = malloc(i + 2);
	if (!temp)
		return (1);
	j = -1;
	while (++j < i)
		temp[j] = buff[j];
	temp[j++] = '\n';
	temp[j] = '\0';
	line = ft_strjoin(line, temp);
	shift_it(buff, i + 1);
	return (1);
}

char	*get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	char	*line;
	int	read_did_it_job;
	int	the_end_has_been_founded;

	line = NULL;
	if (has_the_end(buff, line))
		return (line);
	read_did_it_job = read(fd, buff, BUFFER_SIZE);
	the_end_has_been_founded = has_the_end(buff, line);
	printf("%s", line);
	while (read_did_it_job > 0 && !the_end_has_been_founded)
	{
		read_did_it_job = read(fd, buff, BUFFER_SIZE);
		the_end_has_been_founded = has_the_end(buff, line);
		printf("%s", line);
	}
	return (line);
}