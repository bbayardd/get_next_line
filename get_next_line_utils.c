/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:36:28 by bbayard           #+#    #+#             */
/*   Updated: 2021/11/23 00:36:41 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src || !n)
		return (dest);
	while (i < n)
	{
		*((char *) dest + i) = *((char *) src + i);
		i++;
	}
	return (dest);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sum_s;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[i] = '\0';
	}
	sum_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!sum_s || !s2)
		return (NULL);
	while (s1[c])
		sum_s[i++] = s1[c++];
	c = 0;
	while (s2[c])
		sum_s[i++] = s2[c++];
	sum_s[i] = '\0';
	return (sum_s);
}
