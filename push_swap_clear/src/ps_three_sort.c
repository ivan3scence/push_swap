/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:42:05 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/27 16:40:41 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	ft_check_sort(t_list **stack)
{
	t_list	*elem;
	int		min;
	int		count;

	count = -1;
	elem = *stack;
	min = elem->content;
	while (elem)
	{
		if (min > elem->content)
			return (count);
		count++;
		min = elem->content;
		elem = elem->next;
	}
	return (0);
}

void	ft_sort_three(t_list **stack, t_list **stack_sec, char *str)
{
	int		index;
	t_list	*elem2;
	t_list	*elem3;

	index = ft_check_sort(stack);
	if (index == -1)
		error_ps(stack, stack_sec, 5);
	elem2 = (*stack)->next;
	elem3 = elem2->next;
	if ((index == 0 && elem3->content < elem2->content)
		|| (index == 1 && elem3->content > (*stack)->content))
		op_s(stack, str);
	if ((*stack)->content > elem2->content
		&& (*stack)->content < elem3->content)
		return (op_s(stack, str));
	if ((*stack)->content > elem2->content
		&& (*stack)->content > elem3->content)
		return (op_r(stack, str));
	return (op_r_r(stack, str));
}

void	ft_sort_two(t_list **stack, char *str)
{
	if ((*stack)->content < (*stack)->next->content)
		return ;
	return (op_s(stack, str));
}
