/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:02:20 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/30 16:27:50 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_tools
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		a;
	int		b;
}	t_tools;
typedef struct s_data
{
	int	pivot;
	int	max;
	int	range;
	int	*s_arr;
	int	size;
	int	*arr_a;
	int	*arr_b;
	int	l;
	int	y;
	int	y_t;
	int	z;
}	t_data;
void	fill_args(t_list **stack_a, char **argv);
void	error(int a);
int		is_sorted(t_list *stack_a);
char	**to_split(const char	**argv);
int		check_limits(const char *str);
void	check_duplicate(t_list *stack_a, int *arr);
void	swap(t_list **stack, int a);
void	push(t_list **stack1, t_list **stack2, int a);
void	rotate(t_list **stack, int a);
t_list	*reverse_rotate(t_list *stack, int a);
void	sort_3(t_list **a, int *arr);
void	sort_5_4(t_list **a, t_list **b, int c, t_data data);
int		*fill_arr(t_list **stack, int *arr);
int		max_index(int *arr, int l);
int		*sorted_arr(t_list *stack, int *arr);
void	sort(t_list **a, t_list **b, int chunk, t_data data);
void	to_free(char **splited);

#endif