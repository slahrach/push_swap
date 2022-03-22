/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 04:11:08 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/21 03:17:21 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_limits(const char *str)
{
	int	nbr;

	nbr = ft_atoi(str);
	if ((nbr == 0 && str[0] != '0'))
		error(0);
	if ((nbr == 1 && str[0] == '-')
		|| (nbr == -1 && str[0] != '-'))
		error(0);
	return (nbr);
}

void	check_duplicate(t_list *stack_a)
{
	int		l;
	int		i;
	int		j;

	i = 0;
	l = ft_lstsize(stack_a);
	fill_arr(&stack_a);
	i = -1;
	while (++i < l)
	{
		j = i + 1;
		while (j < l)
		{
			if (stack_a->arr[i] == stack_a->arr[j])
				error (0);
			j++;
		}
	}
}

int	fill_arr(t_list **stack)
{
	int		l;
	int		i;
	t_list	*temp;

	if (!(*stack))
		return (0);
	i = 0;
	l = ft_lstsize(*stack);
	(*stack)->arr = malloc(l * sizeof(int));
	temp = *stack;
	while (temp)
	{
		(*stack)->arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (l);
}

int	*sorted_arr(t_list *stack)
{
	int		*so_arr;
	int		temp;
	t_tools	t;

	t.l = fill_arr(&stack);
	t.i = 0;
	so_arr = malloc (t.l * sizeof(int));
	so_arr = stack->arr;
	while (t.i < t.l)
	{
		t.j = t.i + 1;
		while (t.j < t.l)
		{
			if (so_arr[t.i] < so_arr[t.j])
			{
				temp = so_arr[t.i];
				so_arr[t.i] = so_arr[t.j];
				so_arr[t.j] = temp;
			}
			t.j++;
		}
		t.i++;
	}
	return (so_arr);
}
