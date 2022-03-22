/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:03:14 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/08 02:11:30 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	t_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*t_strdup(char *s1)
{
	char	*ptr;
	size_t	l;

	l = t_strlen(s1);
	ptr = (char *) malloc ((l + 1) * sizeof(char));
	if (!ptr)
		return (0);
	t_strlcpy (ptr, s1, l + 1);
	return (ptr);
}

char	*ft_strnchr(char *s, int c, int *i)
{
	*i = 0;
	while (s[*i] != '\0')
	{
		if (s[(*i)] == (unsigned char)c)
		{
			(*i)++;
			if (s[*i] != '\0')
				return (t_strdup(&s[*i]));
			return (NULL);
		}
		(*i)++;
	}
	*i = -1;
	return (NULL);
}

size_t	t_strlcpy( char *dst, char *src, size_t sizedst)
{
	size_t	l;
	size_t	i;

	l = t_strlen(src);
	i = 0;
	if (sizedst == 0)
		return (l);
	while (src[i] && i < (sizedst - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}

char	*fre_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		b;

	if (!s1)
		return (t_strdup(s2));
	i = 0;
	b = 0;
	str = (char *) malloc (t_strlen (s1) + t_strlen (s2) + 1);
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
	{
		str[i] = s2[b];
		i++;
		b++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
