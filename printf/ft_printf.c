/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:52:51 by slahrach          #+#    #+#             */
/*   Updated: 2021/12/09 01:08:07 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	func(va_list arg_ptr, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = aff_char(va_arg(arg_ptr, int));
	else if (c == '%')
		count = aff_char('%');
	else if (c == 's')
		count = aff_str(va_arg(arg_ptr, char *));
	else if (c == 'd' || c == 'i')
		count = aff_base10(va_arg(arg_ptr, int));
	else if (c == 'u')
		count = aff_unsigned(va_arg(arg_ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		count = aff_base16(va_arg(arg_ptr, int), c);
	else if (c == 'p')
		count = aff_pointer(va_arg(arg_ptr, void *));
	else
		return (count);
	return (count);
}

int	ft_printf(const char *src, ...)
{
	int		r;
	int		i;
	va_list	arg_ptr;

	i = 0;
	r = 0;
	va_start(arg_ptr, src);
	while (src[i] != '\0')
	{
		if (src[i] == '%')
		{
			r += func(arg_ptr, src[i + 1]);
			i += 2;
		}
		else
		{
			aff_char(src[i]);
			i++;
			r++;
		}
	}
	va_end(arg_ptr);
	return (r);
}
