/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:20:14 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/18 12:26:24 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif