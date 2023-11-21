/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:19:56 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/21 11:57:21 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*s_dup;
	size_t	i;

	s_dup = malloc(ft_strlen(str) + 1);
	if (!s_dup)
		return (NULL);
	i = -1;
	while (str[++i])
		s_dup[i] = str[i];
	s_dup[i] = '\0';
	return (s_dup); 
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if ((!s1 && !s2))
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	new_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_s)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_s[i] = s1[i];
	j = 0;
	while (s2[j])
		new_s[i++] = s2[j++];
	new_s[i] = '\0';
	free(s1);
	free(s2);
	return (new_s);
}
