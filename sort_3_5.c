/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:16:26 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/30 15:10:26 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_index(int *arr, int l)
{
	int	min;
	int	i;

	i = 0;
	min = 0;
	while (i < l)
	{
		if (arr[i] < arr[min])
			min = i;
		i++;
	}
	return (min);
}

void	sort_3(t_list **a, int *arr)
{
	if (is_sorted(*a))
		return ;
	if ((arr[0] > arr[1]) && arr[0] < arr[2])
		swap(a, 'a');
	else if (arr[0] < arr[1] && arr[0] < arr[2])
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		swap(a, 'a');
		*a = reverse_rotate(*a, 'a');
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2])
		rotate(a, 'a');
	else if (arr[0] < arr[1] && arr[1] > arr[2])
	{
		*a = reverse_rotate(*a, 'a');
	}
}

void	b_to_a(int l, int i, t_list **b, t_list **a)
{
	int	t;

	if (i <= l / 2)
	{
		t = i;
		while (t-- > 0)
			rotate(a, 'a');
		push(b, a, 'a');
		while (i-- > 0)
			*a = reverse_rotate(*a, 'a');
	}
	else if (i > l / 2)
	{
		t = l - i;
		while (t-- > 0)
			*a = reverse_rotate(*a, 'a');
		push(b, a, 'a');
		t = (l - i) + 1;
		while (t > 0)
		{
			rotate(a, 'a');
			t--;
		}
	}
}

void	sort_5_4(t_list **a, t_list **b, int c, t_data data)
{
	int		i;
	int		l;

	l = ft_lstsize(*a);
	data.arr_a = fill_arr(a, data.arr_a);
	if (min_index (data.arr_a, l) == l - 1)
		*a = reverse_rotate(*a, 'a');
	push(a, b, 'b');
	if (c == 2)
		push(a, b, 'b');
	data.arr_a = fill_arr(a, data.arr_a);
	sort_3(a, data.arr_a);
	while (c-- > 0)
	{
		l = ft_lstsize(*a);
		data.arr_a = fill_arr(a, data.arr_a);
		data.arr_b = fill_arr(b, data.arr_b);
		i = -1;
		while (++i < l)
		{
			if (data.arr_b[0] < data.arr_a[i])
				break ;
		}
		b_to_a(l, i, b, a);
	}
}
