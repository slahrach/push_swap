/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 06:16:17 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/30 16:42:46 by slahrach         ###   ########.fr       */
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

void	action(t_data p, t_list **stack1, t_list **stack2)
{
	int	j;

	if (p.max <= (p.size) / 2)
	{
		while (p.max > 0)
		{
			rotate(stack1, 'b');
			(p.max)--;
		}
		push(stack1, stack2, 'a');
	}
	else
	{
		j = p.size - p.max;
		while (j > 0)
		{
			*stack1 = reverse_rotate(*stack1, 'b');
			j--;
		}
		push(stack1, stack2, 'a');
	}
}

int	a_to_b_process(t_data *p, t_list **a, t_list **b, int *arr_a)
{
	arr_a = fill_arr(a, arr_a);
	if (p->s_arr[p->y] == arr_a[0])
	{
		push(a, b, 'b');
		if (p->s_arr[p->y] < p->pivot && ft_lstsize(*b))
		{
			if (arr_a[1] > p->s_arr[p->y_t] || arr_a[1] < p->s_arr[p->z])
			{
				rotate(a, 'c');
				rotate(b, 'c');
				ft_printf("rr\n");
			}
			else
				rotate(b, 'b');
		}
		return (1);
	}
	return (0);
}

static	void	a_to_b(t_data *push_swap, t_list **a, t_list **b, t_data data)
{
	int	i;

	i = 0;
	while (i < push_swap->size)
	{
		push_swap->y = (data.l / 2) - push_swap->range;
		if (push_swap->y < 0)
			push_swap->y = 0;
		push_swap->y_t = push_swap->y;
		push_swap->z = (data.l / 2) + push_swap->range;
		if (push_swap->z > data.l)
			push_swap->z = data.l;
		while (push_swap->y < push_swap->z)
		{
			if (a_to_b_process(push_swap, a, b, data.arr_a) == 1)
				break ;
			push_swap->y++;
		}
		if (push_swap->y == push_swap->z)
			rotate(a, 'a');
		i++;
	}
}

void	sort(t_list **a, t_list **b, int chunk, t_data data)
{
	t_data	push_swap;

	push_swap.range = 0;
	push_swap.s_arr = sorted_arr(*a, data.arr_a);
	push_swap.pivot = push_swap.s_arr[data.l / 2];
	push_swap.size = data.l;
	while (push_swap.size)
	{
		data.arr_a = fill_arr(a, data.arr_a);
		push_swap.range += chunk;
		a_to_b(&push_swap, a, b, data);
		push_swap.size = ft_lstsize(*a);
	}
	free(push_swap.s_arr);
	push_swap.size = data.l;
	while (push_swap.size)
	{
		data.arr_b = fill_arr(b, data.arr_b);
		push_swap.max = max_index(data.arr_b, push_swap.size);
		action(push_swap, b, a);
		push_swap.size = ft_lstsize(*b);
	}
}
