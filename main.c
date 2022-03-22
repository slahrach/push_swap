/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:53:20 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/22 00:28:05 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose(t_list **a, t_list **b, int l)
{
	if (l == 2)
		swap(a, 'a');
	else if (l == 3)
		sort_3(a);
	else if (l <= 5)
		sort_5(a, b);
	else if (l <= 100)
		sort(a, b, l, 11);
	else
		sort(a, b, l, 22);
}

int	main(int argc, const char **argv)
{
	t_list	*a;
	t_list	*b;
	int		l;
	int		i;
	char	**splited;

	b = NULL;
	a = NULL;
	if (argc < 2)
		exit(0);
	i = 0;
	splited = to_split(argv);
	fill_args(&a, splited);
	check_duplicate(a);
	if (!is_sorted(a))
	{
		l = ft_lstsize(a);
		choose(&a, &b, l);
	}
	return (0);
}
