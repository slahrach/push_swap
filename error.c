/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:23:49 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/30 12:46:59 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int a)
{
	if (a == 0)
		write(2, "Error\n", 6);
	else if (a == 1)
		write(2, "allocation failed :(", 21);
	exit(0);
}

void	to_free(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}
