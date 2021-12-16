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

void	op_s(t_list **stack, char *str)
{
	int	tmp;

	if (!(stack && *stack && (*stack)->next))
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (!ft_strncmp(str, "ss", 2))
		return (ft_putstr_fd("ss\n", 1));
	if (str)
	{
		ft_putchar_fd('s', 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	op_ss(t_list **a, t_list **b)
{
	op_s(a, NULL);
	op_s(b, "ss");
}

void	op_p(t_list **stack_to, t_list **stack_from, char *str)
{
	t_list	*tmp;

	if (!(stack_from && (*stack_from)))
		return ;
	tmp = *stack_from;
	if (tmp->next)
		*stack_from = tmp->next;
	else
		*stack_from = NULL;
	ft_lstadd_front(stack_to, tmp);
	ft_putchar_fd('p', 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}
