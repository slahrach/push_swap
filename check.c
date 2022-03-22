/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:06:20 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/21 03:16:35 by slahrach         ###   ########.fr       */
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
			t.l++;
			t.j++;
		}
	}
	t.j = 0;
	ret = (char **) malloc ((t.l + 1) * sizeof(char *));
	t.i = 0;
	while (t.i < t.l)
	{
		ret[t.i] = (char *) malloc ((12) * sizeof(char));
		t.i++;
	}
	return (ret);
}

static char	**fill(const char	**argv, t_tools *t, char **ret)
{
	char	**spl;

	if (ft_strlen(argv[t->i]) > 1)
	{
		t->j = -1;
		spl = ft_split(argv[t->i], ' ');
		while (spl[++t->j])
		{
			t->k = 0;
			t->b = 0;
			while (spl[t->j][t->k])
				ret[t->a][t->b++] = spl[t->j][t->k++];
			ret[t->a++][t->b] = '\0';
		}
	}
	else
	{
		ret[t->a][0] = argv[t->i][0];
		ret[t->a++][1] = '\0';
	}
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
/*
int	main(int argc, const char **argv)
{
	char	**str;
	int		i;

	i = 0;
	str = to_split(argv);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	printf("%d\n", ft_atoi("-2147483649"));
}*/
