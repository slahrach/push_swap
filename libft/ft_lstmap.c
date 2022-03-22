/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:21:47 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/13 22:37:38 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*head;
	t_list	*new;
	t_list	*cpy;

	if (!lst || !f)
		return (NULL);
	cpy = lst;
	head = NULL;
	while (cpy)
	{
		new = ft_lstnew(f(cpy->content));
		if (!new)
			ft_lstclear(&head, del);
		ft_lstadd_back(&head, new);
		cpy = cpy->next;
	}
	return (head);
}
