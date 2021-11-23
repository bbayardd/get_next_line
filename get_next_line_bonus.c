/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:35:24 by bbayard           #+#    #+#             */
/*   Updated: 2021/11/23 00:35:29 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*parsing(char *saved_str)
{
	int		i;
	char	*new_str;
	int		c;

	i = 0;
	c = 0;
	while (saved_str[i] != '\n')
		i++;
	if (!saved_str[i])
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(saved_str) - i + 1));
	if (!new_str)
		return (NULL);
	while (saved_str[++i])
		new_str[c++] = saved_str[i];
	new_str[c] = '\0';
	free(saved_str);
	return (new_str);
}

char	*ret_value(char *saved_str)
{
	size_t	i;
	char	*ret_str;

	i = 0;
	while (saved_str[i] != '\n' && saved_str[i])
		i++;
	if (saved_str[i] == '\n')
		i++;
	ret_str = malloc(sizeof(char) * (i + 2));
	if (!ret_str)
		return (NULL);
	ft_memcpy(ret_str, saved_str, i);
	ret_str[++i] = '\0';
	return (ret_str);
}

char	*search_n(char *saved_str)
{
	int	i;

	i = 0;
	if (!saved_str)
	{
		return (NULL);
	}
	while (saved_str[i] != '\n' && saved_str[i])
		i++;
	if (saved_str[i] != '\n')
		return (NULL);
	return ((char *)&saved_str[i]);
}

static char	*make_line(int fd, char *saved_str)
{
	char	*buf;
	int		rd;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	while (!search_n(saved_str) && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		saved_str = ft_strjoin(saved_str, buf);
	}
	free(buf);
	return (saved_str);
}

char	*get_next_line(int fd)
{
	char		*printbl_str;
	static char	*saved_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_str[fd] = make_line(fd, saved_str[fd]);
	if (!saved_str[fd])
		return (NULL);
	printbl_str = ret_value(saved_str[fd]);
	saved_str[fd] = parsing(saved_str[fd]);
	return (printbl_str);
}
