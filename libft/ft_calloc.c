/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:32:37 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/23 03:57:14 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	a;

	a = count * size;
	ptr = (void *) malloc (a);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, a);
	return (ptr);
}
