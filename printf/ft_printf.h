/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:01:57 by slahrach          #+#    #+#             */
/*   Updated: 2021/12/09 00:23:47 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	aff_char(int c);
int	aff_str(char *str);
int	aff_base10(int n);
int	aff_unsigned(unsigned int nbr);
int	aff_base16(unsigned int n, char la);
int	aff_pointer(void *ptr);
int	ft_printf(const char *src, ...);

#endif
