/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:16:26 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/21 03:17:45 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	if (is_sorted(*a))
		return ;
	if (((*a)->arr[0] > (*a)->arr[1]) && (*a)->arr[0] < (*a)->arr[2])
		swap(a, 'a');
	else if ((*a)->arr[0] < (*a)->arr[1] && (*a)->arr[0] < (*a)->arr[2])
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if ((*a)->arr[0] > (*a)->arr[1] && (*a)->arr[1] > (*a)->arr[2])
	{
		swap(a, 'a');
		*a = reverse_rotate(*a, 'a');
	}
	else if ((*a)->arr[0] > (*a)->arr[1] && (*a)->arr[1] < (*a)->arr[2])
		rotate(a, 'a');
	else if ((*a)->arr[0] < (*a)->arr[1] && (*a)->arr[1] > (*a)->arr[2])
	{
		*a = reverse_rotate(*a, 'a');
	}
}

void	sort_5(t_list **a, t_list **b)
{
	int	i;
	int	l;
	int	j;
	int	k;
	int	c;
	int	l_b;

	c = 0;
	push(a, b, 'b');
	push(a, b, 'b');
	l_b = fill_arr(b);
	l = fill_arr(a);
	sort_3(a);
	l = fill_arr(a);
	while (c < 2)
	{
		i = 0;
		while (i < l)
		{
			if ((*b)->arr[0] < (*a)->arr[i])
				break ;
			i++;
		}
		if (i == 0 || i == 1)
		{
			push(b, a, 'a');
			if (i == 1)
				swap(a, 'a');
		}
		else if (i <= l / 2)
		{
			j = i;
			while (i > 0)
			{
				rotate(a, 'a');
				i--;
			}
			push(b, a, 'a');
			while (j > 0)
			{
				*a = reverse_rotate(*a, 'a');
				j--;
			}
		}
		else if (i > l / 2)
		{
			if (i == l)
			{
				push(b, a, 'a');
				rotate(a, 'a');
			}
			else
			{
				j = l - i;
				k = j + 1;
				while (j > 0)
				{
					*a = reverse_rotate(*a, 'a');
					j--;
				}
				push(b, a, 'a');
				while (k > 0)
				{
					rotate(a, 'a');
					k--;
				}
			}
		}
		l_b = fill_arr(b);
		l = fill_arr(a);
		c++;
	}
}
