/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:56:37 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/23 03:58:42 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t count)
{
	int	i;

	i = 0;
	while (count > 0)
	{
		*(unsigned char *)(ptr + i) = (unsigned char)x;
		i++;
		count--;
	}
	return (ptr);
}
