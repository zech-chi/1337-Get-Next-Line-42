/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:28:20 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/17 16:55:59 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr); 
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		ptr = ft_strdup(s2);
		free(s2);
		return (ptr);
	}
	if (!s2)
	{
		ptr = ft_strdup(s1);
		free(s1);
		return (ptr);
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	if (size > 0)
	{
		j = 0;
		while (s1[j])
			ptr[i++] = s1[j++];
		j = 0;
		while (s2[j])
			ptr[i++] = s2[j++];
	}
	ptr[i] = 0;
	free(s1);
	free(s2);
	return (ptr);
}
