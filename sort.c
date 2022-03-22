/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 06:16:17 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/22 02:23:56 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index(int *arr, int l)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (i < l)
	{
		if (arr[i] > arr[max])
			max = i;
		i++;
	}
	return (max);
}

void	action(int l, int index, t_list **stack1, t_list **stack2, int a, int b)
{
	int	j;

	if (index <= l / 2)
	{
		while (index > 0)
		{
			rotate(stack1, a);
			index--;
		}
		push(stack1, stack2, b);
	}
	else
	{
		j = l - index;
		while (j > 0)
		{
			*stack1 = reverse_rotate(*stack1, a);
			j--;
		}
		push(stack1, stack2, b);
	}
}

int	a_to_b_process(t_data *push_swap, t_list **a, t_list **b, int y)
{
	fill_arr(a);
	if (push_swap->s_arr[y] == (*a)->arr[0])
	{
		push(a, b, 'b');
		if (push_swap->s_arr[y] < push_swap->pivot && ft_lstsize(*b))
			rotate(b, 'b');
		return (1);
	}
	return (0);
}

static	void	a_to_b(t_data *push_swap, int l, t_list **a, t_list **b)
{
	int	i;
	int	y;
	int	z;

	i = 0;
	while (i < push_swap->size)
	{
		y = (l / 2) - push_swap->range;
		if (y < 0)
			y = 0;
		z = (l / 2) + push_swap->range;
		if (z > l)
			z = l;
		while (y < z)
		{
			if (a_to_b_process(push_swap, a, b, y) == 1)
				break ;
			y++;
		}
		if (y == z)
			rotate(a, 'a');
		i++;
	}
}

void	sort(t_list **a, t_list **b, int l, int chunk)
{
	int		max;
	t_data	push_swap;

	push_swap.range = 1;
	push_swap.s_arr = sorted_arr(*a);
	push_swap.pivot = push_swap.s_arr[l / 2];
	push_swap.size = fill_arr(a);
	while ((push_swap.size))
	{
		push_swap.range += chunk;
		a_to_b(&push_swap, l, a, b);
		push_swap.size = fill_arr(a);
	}
	push_swap.size = fill_arr(b);
	while (push_swap.size)
	{
		max = max_index((*b)->arr, push_swap.size);
		action(push_swap.size, max, b, a, 'b', 'a');
		push_swap.size = fill_arr(b);
	}
}
