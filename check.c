/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:06:20 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/30 14:03:17 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_args(t_list **stack_a, char **splited)
{
	int		nbr;
	t_list	*new;
	int		i;

	i = 0;
	while (splited[i])
	{
		nbr = check_limits(splited[i]);
		new = ft_lstnew(nbr);
		ft_lstadd_back(stack_a, new);
		i++;
	}
}

int	is_sorted(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
	if (temp->next == NULL)
		return (1);
	while (temp)
	{
		if (temp->next)
			if ((temp->content) > (temp->next->content))
				return (0);
		temp = temp->next;
	}
	return (1);
}

static char	**allocate(const char **argv)
{
	t_tools	t;
	char	**ret;

	t.i = 0;
	t.l = 0;
	while (argv[++t.i])
	{
		(t.l)++;
		t.j = 0;
		while (argv[t.i][t.j])
		{
			if (argv[t.i][t.j] == ' ')
			(t.l)++;
			t.j++;
		}
	}
	t.j = 0;
	ret = malloc (((t.l) + 1) * sizeof(char *));
	return (ret);
}

static char	**fill(const char	**argv, t_tools *t, char **ret)
{
	char	**spl;

	t->j = 0;
	spl = ft_split(argv[t->i], ' ');
	while (spl[t->j])
	{
		ret[t->a] = ft_strdup(spl[t->j]);
		t->j++;
		t->a++;
	}
	to_free(spl);
	return (ret);
}

char	**to_split(const char **argv)
{
	char	**ret;
	t_tools	t;

	ret = allocate (argv);
	t.a = 0;
	t.i = 0;
	while (argv[++t.i])
	{
		ret = fill (argv, &t, ret);
	}
	ret[t.a] = NULL;
	return (ret);
}
