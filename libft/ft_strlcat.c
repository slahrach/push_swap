/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:54:55 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/23 04:00:35 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	l;
	size_t	i;

	src_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	l = dst_len + src_len;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (l);
}
