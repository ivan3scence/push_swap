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

void	op_r(t_list **stack, char *str)
{
	t_list	*tmp;

	if (!(stack && *stack))
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	tmp = NULL;
	if (!ft_strncmp(str, "rr", 2))
		return (ft_putstr_fd("rr\n", 1));
	if (str)
	{
		ft_putchar_fd('r', 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	op_rr(t_list **a, t_list **b)
{
	op_r(a, NULL);
	op_r(b, "rr");
}

static void	ft_lstprev(t_list **stack, t_list *elem)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != elem)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	op_r_r(t_list **stack, char *str)
{
	t_list	*tmp;

	if (!(stack && *stack))
		return ;
	tmp = ft_lstlast(*stack);
	ft_lstadd_front(stack, ft_lstnew(tmp->content));
	ft_lstdelone(tmp, NULL);
	ft_lstprev(stack, tmp);
	if (!ft_strncmp(str, "rrr", 3))
		return (ft_putstr_fd("rrr\n", 1));
	if (*str)
	{
		ft_putstr_fd("rr", 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	op_rrr(t_list **a, t_list **b)
{
	op_r_r(a, NULL);
	op_r_r(b, "rrr");
}
