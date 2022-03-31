/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 04:11:08 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/30 14:11:20 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_limits(const char *str)
{
	int	nbr;

	nbr = ft_atoi(str);
	if ((nbr == 0 && str[0] != '0')
		|| (nbr == 0 && str[0] == '0' && (ft_strlen(str) != 1)))
		error(0);
	if ((nbr == 1 && str[0] == '-')
		|| (nbr == -1 && str[0] != '-'))
		error(0);
	return (nbr);
}

void	check_duplicate(t_list *stack_a, int *arr)
{
	int		l;
	int		i;
	int		j;

	arr = fill_arr(&stack_a, arr);
	l = ft_lstsize(stack_a);
	i = -1;
	while (++i < l)
	{
		j = i + 1;
		while (j < l)
		{
			if (arr[i] == arr[j])
			{
				error (0);
			}
			j++;
		}
	}
}

int	*fill_arr(t_list **stack, int *arr)
{
	int		i;
	t_list	*temp;

	if (!(*stack))
		return (0);
	i = 0;
	temp = *stack;
	while (temp)
	{
		arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (arr);
}

int	*sorted_arr(t_list *stack, int *arr)
{
	int		*so_arr;
	int		temp;
	t_tools	t;

	t.l = ft_lstsize(stack);
	arr = fill_arr(&stack, arr);
	t.i = -1;
	so_arr = malloc (t.l * sizeof(int));
	while (++t.i < t.l)
		so_arr[t.i] = arr[t.i];
	t.i = -1;
	while (++t.i < t.l)
	{
		t.j = t.i;
		while (++t.j < t.l)
		{
			if (so_arr[t.i] < so_arr[t.j])
			{
				temp = so_arr[t.i];
				so_arr[t.i] = so_arr[t.j];
				so_arr[t.j] = temp;
			}
		}
	}
	return (so_arr);
}
