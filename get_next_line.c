/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:36:27 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/21 10:58:02 by zech-chi         ###   ########.fr       */
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

int	has_the_end(char *buff, char **line)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (i < BUFFER_SIZE && buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (i == BUFFER_SIZE || buff[i] == '\0')
	{
		*line = ft_strjoin(*line, ft_strdup(buff));
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
	*line = ft_strjoin(*line, temp);
	shift_it(buff, i + 1);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			read_did_it_job;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (has_the_end(buff, &line))
		return (line);
	while ((read_did_it_job = read(fd, buff, BUFFER_SIZE)) > 0
		&& !(has_the_end(buff, &line)));
	if (read_did_it_job == -1 || (line && ft_strlen(line) == 0))
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
