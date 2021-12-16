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

static int	check_alive(t_list **stack)
{
	t_list	*elem;

	elem = *stack;
	while (elem)
	{
		if (elem->content)
			return (1);
		elem = elem->next;
	}
	return (0);
}

static void	push_zeroend(t_list **a_stack, t_list **b_stack, int len)
{
	t_list	*elem;
	int		i;

	i = -1;
	elem = *a_stack;
	while (++i < len)
	{
		if ((elem->content & 1) == 0)
		{
			elem->content = elem->content / 2;
			op_p(b_stack, a_stack, "b");
		}
		else
		{
			elem->content = elem->content / 2;
			op_r(a_stack, "a");
		}
		elem = *a_stack;
	}
}

static void	push_back(t_list **a_stack, t_list **b_stack)
{
	while (*b_stack)
		op_p(a_stack, b_stack, "a");
}

void	push_radix(t_list **a_stack, t_list **b_stack, int len)
{
	while (check_alive(a_stack))
	{
		push_zeroend(a_stack, b_stack, len);
		push_back(a_stack, b_stack);
	}
}
