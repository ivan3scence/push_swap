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

static void	insert(t_list **a_stack, t_list **b_stack, int order)
{
	int	min;
	int	flag;

	flag = 0;
	min = (*a_stack)->content;
	if (ft_lstlast(*a_stack)->content - 1 != (*b_stack)->content)
	{
		while ((*a_stack)->content < (*b_stack)->content)
			op_r(a_stack, "a");
		flag = 1;
	}
	else
		op_r_r(a_stack, "a");
	while (order && *b_stack)
		op_p(a_stack, b_stack, "a");
	if (!order)
		op_p(a_stack, b_stack, "a");
	while (min != (*a_stack)->content)
	{
		if (flag)
			op_r_r(a_stack, "a");
		else
			op_r(a_stack, "a");
	}	
}

static int	in_order(t_list **stack)
{
	t_list	*elem;

	elem = *stack;
	while (elem)
	{
		if (elem->next && elem->content != elem->next->content + 1)
			return (0);
		elem = elem->next;
	}
	return (1);
}

static void	start_fivesort(t_list **a_stack, t_list **b_stack, int len)
{
	op_p(b_stack, a_stack, "b");
	if (len == 5)
		op_p(b_stack, a_stack, "b");
	if ((*b_stack)->next && (*b_stack)->content < (*b_stack)->next->content)
		op_s(b_stack, "b");
	if (is_sorted(a_stack) == 0)
		ft_sort_three(a_stack, b_stack, "a");
}

void	ft_sort_five(t_list **a_stack, t_list **b_stack, int len)
{
	int	order;

	start_fivesort(a_stack, b_stack, len);
	order = in_order(b_stack);
	while (*b_stack)
	{
		if ((*a_stack)->content > (*b_stack)->content)
		{
			if (order)
			{
				while (*b_stack)
					op_p(a_stack, b_stack, "a");
			}
			else
				op_p(a_stack, b_stack, "a");
		}
		else if (ft_lstlast(*a_stack)->content < (*b_stack)->content)
		{
			op_p(a_stack, b_stack, "a");
			op_r(a_stack, "a");
		}
		else
			insert(a_stack, b_stack, order);
	}
}
