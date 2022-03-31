/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:41:54 by slahrach          #+#    #+#             */
/*   Updated: 2021/12/09 00:45:03 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned int n)
{
	int	r;

	r = 1;
	while (n > 9)
	{
		r++;
		n /= 10;
	}
	return (r);
}

int	aff_unsigned(unsigned int nbr)
{
	int		a;

	a = count(nbr);
	if (nbr < 10)
		aff_char(nbr + '0');
	else
	{
		aff_unsigned(nbr / 10);
		aff_char((nbr % 10) + '0');
	}
	return (a);
}
