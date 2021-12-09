#include "pushswap.h"

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

void	ft_lstprev(t_list **stack, t_list *elem)
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