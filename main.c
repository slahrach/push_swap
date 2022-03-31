/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:53:20 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/30 17:03:04 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose(t_list **a, t_list **b, t_data data)
{
	if (data.l == 2)
		swap(a, 'a');
	else if (data.l == 3)
		sort_3(a, data.arr_a);
	else if (data.l == 4)
		sort_5_4(a, b, 1, data);
	else if (data.l == 5)
		sort_5_4(a, b, 2, data);
	else if (data.l <= 100)
		sort(a, b, 11, data);
	else
		sort(a, b, 22, data);
}

int	main(int argc, const char **argv)
{
	t_data	data;
	t_list	*a;
	t_list	*b;
	char	**splited;

	b = NULL;
	a = NULL;
	if (argc < 2)
		exit(0);
	splited = to_split(argv);
	fill_args(&a, splited);
	to_free(splited);
	data.l = ft_lstsize(a);
	data.arr_a = malloc (data.l * sizeof (int));
	data.arr_b = malloc (data.l * sizeof (int));
	check_duplicate(a, data.arr_a);
	if (!is_sorted(a))
		choose(&a, &b, data);
	return (0);
}
