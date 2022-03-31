/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:32:23 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/30 16:51:48 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static	void	double_op(t_list **a, t_list **b, char *op)
{
	if (!ft_strcmp (op, "ss\n"))
	{
		swap(a, 'c');
		swap(b, 'c');
	}
	else if (!ft_strcmp (op, "rr\n"))
	{
		rotate(a, 'c');
		rotate(b, 'c');
	}
	else if (!ft_strcmp (op, "rrr\n"))
	{
		*a = reverse_rotate(*a, 'c');
		*b = reverse_rotate(*b, 'c');
	}
	else
		error(0);
}

static	void	find_operation(t_list **a, t_list **b, char *op)
{
	if (!ft_strcmp (op, "sa\n"))
		swap(a, 'c');
	else if (!ft_strcmp (op, "sb\n"))
		swap(b, 'c');
	else if (!ft_strcmp (op, "ra\n"))
		rotate(a, 'c');
	else if (!ft_strcmp (op, "rb\n"))
		rotate(b, 'c');
	else if (!ft_strcmp (op, "rra\n"))
		*a = reverse_rotate(*a, 'c');
	else if (!ft_strcmp (op, "rrb\n"))
		*b = reverse_rotate(*b, 'c');
	else if (!ft_strcmp (op, "pa\n"))
		push(b, a, 'c');
	else if (!ft_strcmp (op, "pb\n"))
		push(a, b, 'c');
	else
		double_op (a, b, op);
}

void	result(t_list *a, t_list *b)
{
	if (is_sorted(a) && ft_lstsize(b) == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int argc, const char **argv)
{
	char	*op;
	t_list	*a;
	int		*arr_a;
	t_list	*b;
	char	**splited;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(0);
	splited = to_split(argv);
	fill_args(&a, splited);
	to_free(splited);
	arr_a = malloc (ft_lstsize(a) * sizeof (int));
	check_duplicate(a, arr_a);
	op = get_next_line(0);
	while (op)
	{
		find_operation(&a, &b, op);
		free(op);
		op = get_next_line(0);
	}
	result(a, b);
}
