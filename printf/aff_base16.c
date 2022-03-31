/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_base16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 02:53:26 by slahrach          #+#    #+#             */
/*   Updated: 2021/12/09 00:33:54 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned int n)
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

int	aff_base16(unsigned int nbr, char la)
{
	int		r;
	char	*str;

	r = count(nbr);
	if (la == 'x')
		str = "0123456789abcdef";
	else if (la == 'X')
		str = "0123456789ABCDEF";
	if (nbr < 16)
		aff_char(str[nbr]);
	else
	{
		aff_base16((nbr / 16), la);
		aff_char(str[nbr % 16]);
	}
	return (r);
}
