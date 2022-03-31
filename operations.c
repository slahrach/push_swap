/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:01 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/28 13:57:20 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, int a)
{
	int	temp;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (a == 'a' || a == 'b')
		ft_printf("s%c\n", a);
}

void	push(t_list **stack1, t_list **stack2, int a)
{
	t_list	*temp;

	if (*stack1 == NULL)
		return ;
	if (*stack2 == NULL)
		*stack2 = ft_lstnew((*stack1)->content);
	else
		ft_lstadd_front(stack2, ft_lstnew((*stack1)->content));
	temp = ((*stack1)->next);
	free(*stack1);
	*stack1 = temp;
	if (a == 'a' || a == 'b')
		ft_printf("p%c\n", a);
}

void	rotate(t_list **stack, int a)
{
	int		temp;
	t_list	*temp2;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = (*stack)->content;
	temp2 = (*stack)->next;
	free(*stack);
	*stack = temp2;
	ft_lstadd_back(stack, ft_lstnew(temp));
	if (a == 'a' || a == 'b')
		ft_printf("r%c\n", a);
}

t_list	*reverse_rotate(t_list *stack, int a)
{
	int		l;
	int		i;
	t_list	*ret;
	t_list	*last;

	if (ft_lstsize(stack) < 2)
		return (stack);
	i = 1;
	ret = stack;
	l = ft_lstsize(stack);
	if (l == 0)
		return (NULL);
	last = ft_lstlast(stack);
	while (i < l - 1)
	{
		stack = stack->next;
		i++;
	}
	stack->next = NULL;
	ft_lstadd_front(&ret, last);
	if (a == 'a' || a == 'b')
		ft_printf("rr%c\n", a);
	return (ret);
}
