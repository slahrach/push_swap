/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:05:21 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/23 04:00:41 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy( char *dst, const char *src, size_t sizedst)
{
	size_t	l;
	size_t	i;

	l = ft_strlen(src);
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
