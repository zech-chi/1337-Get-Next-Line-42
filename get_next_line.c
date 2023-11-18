/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:24:12 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/18 12:48:35 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char	*line;
	int		num_read;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	
	
	num_read = read(fd, buff, BUFFER_SIZE);
	if (num_read <= 0)
		
}