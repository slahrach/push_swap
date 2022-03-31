/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 04:23:40 by slahrach          #+#    #+#             */
/*   Updated: 2021/12/09 00:34:25 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned long n)
{
	int	r;

	r = 1;
	while (n > 15)
	{
		r++;
		n /= 16;
	}
	return (r);
}

int	aff_base(unsigned long nbr)
{
	int		r;
	char	*str;

	r = count(nbr);
	str = "0123456789abcdef";
	if (nbr < 16)
		aff_char(str[nbr]);
	else
	{
		aff_base(nbr / 16);
		aff_char(str[nbr % 16]);
	}
	return (r);
}

int	aff_pointer(void *ptr)
{
	int				r;
	unsigned long	nbr;

	nbr = (unsigned long)ptr;
	r = aff_str("0x");
	r += aff_base(nbr);
	return (r);
}
