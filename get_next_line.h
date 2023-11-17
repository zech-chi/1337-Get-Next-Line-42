/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:28:11 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/17 18:04:24 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>  // for malloc and free
#include <unistd.h>  // for read

/*this function return the line that was read*/
/*if there is nothing to read or if an error got, it will return NULL*/


char *get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif