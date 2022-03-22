/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:02:51 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/21 23:32:40 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strndup(char *s1, int l)
{
	char		*ptr;

	ptr = (char *) malloc ((l + 1) * sizeof(char));
	if (!ptr)
		return (0);
	t_strlcpy (ptr, s1, l + 1);
	return (ptr);
}

char	*t_strchr(char *s, int c)
{
	size_t	l;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = t_strlen(s);
	while (i <= l)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

static	char	*funct(char **store, char *buf, int fd, int *pr)
{
	int		i;
	char	*left;
	char	*line;

	while ((*pr) > 0 || t_strchr(*store, '\n'))
	{
		buf[(*pr)] = '\0';
		*store = fre_strjoin(*store, buf);
		left = ft_strnchr(*store, '\n', &i);
		if (i != -1)
		{
			line = ft_strndup(*store, i);
			free(*store);
			if (left)
				*store = left;
			else
				*store = NULL;
			return (line);
		}
		*pr = read(fd, buf, 1);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*retur;
	static char	*store;
	char		*buf;
	int			r;
	char		*ret;

	buf = (char *) malloc (2 * sizeof(char));
	r = read(fd, buf, 1);
	if (r > 0 || t_strchr(store, '\n'))
	{
		retur = funct(&store, buf, fd, &r);
		free(buf);
		if (retur)
			return (retur);
	}
	else
		free(buf);
	if (store != NULL)
	{
		ret = t_strdup(store);
		free(store);
		store = NULL;
		return (ret);
	}
	return (NULL);
}
