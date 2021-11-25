/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:42:05 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/23 16:31:45 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error_ps(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

static void	check_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argc > ++i)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
				error_ps();
		}
	}
}

static void	check_int(int argc, char **argv)
{
	char	otric;
	int		i;

	otric = 0;
	while (--argc > 0)
	{
		i = -1;
		if (argv[argc][++i] == '+' || argv[argc][i] == '-')
		{
			if (argv[argc][i] == '-')
				otric = 1;
			++i;
		}
		//ft_putstr_fd(&argv[argc][i], 1);
		if (ft_strlen(&argv[argc][i]) > 10
			|| (!otric && ft_strlen(&argv[argc][i]) == 10
				&& ft_strncmp("2147483647", &argv[argc][i], 12) < 0)
			|| (otric && ft_strlen(&argv[argc][i]) == 10
				&& ft_strncmp("2147483648", &argv[argc][i], 12) < 0))
			   error_ps();
	}
}	

static void	check_dups(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;

	argc--;
	j = -1;
	while (argc > ++j)
	{
		i = -1;
		while (++i < j)
		{
			n = -1;
			while (argv[i][++n] && argv[j][n])
			{
				if (argv[i][n] != argv[j][n])
				break ;
			}
			if (!argv[i][n] && !argv[j][n])
					error_ps();
		}
	}
}

static t_list	**validate(int argc, char **argv)
{
	t_list	**a_stack;
	// t_list	*elem;
	int		i;

	i = 0;
	check_digits(argc, argv);
	check_int(argc, argv);
	check_dups(argc, argv);
	// ft_putstr_fd("asd\n", 1);
	// elem = ft_lstnew(ft_atoi(argv[1]));
	// a_stack = &elem;
	a_stack = (t_list **)malloc(sizeof(t_list *) * (argc - 1));
	if (!a_stack)
		exit(0);
	*a_stack = NULL;	
	while (argc > ++i)
		ft_lstadd_back(a_stack, ft_lstnew(ft_atoi(argv[i])));
	// ft_putstr_fd("asd\n", 1);
	// ft_putnbr_fd((*a_stack)->content, 1);
	return (a_stack);
}

void	op_s(t_list **stack, char *str)
{
	// t_list	*first;
	int	tmp;

	if (!(stack && *stack && (*stack)->next))
		return ;
	// first = *stack;
	// stack = &(first->next);
	// first->next = (*stack)->next;
	// (*stack)->next = first;
	// first = NULL;

	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (str)
	{
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
	// ft_lstadd_front(stack_to, tmp);
	*stack_from = tmp->next;
	ft_lstadd_front(stack_to, tmp);
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
	// tmp->next = NULL;
	tmp = NULL;
	if (str)
	{
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
	if (*str)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	op_rrr(t_list **a, t_list **b)
{
	op_r_r(a, NULL);
	op_r_r(b, "rrr");
}

// t_list	**createbstack(int size)
// {
// 	t_list	**b_stack;
// 	t_list	*elem;

// 	if (size < 1)
// 	{
// 		ft_lstclear(a_stack, NULL);
// 		exit(0);
// 	}

// }



void	lst_print(t_list **stack)
{
	t_list	*elem;

	elem = *stack;
	while (elem != NULL)
	{
		ft_putnbr_fd(elem->content, 1);
		elem = elem->next;
	}
}

// int	sort(t_list **a_stack)
// {
// 	t_list	*elem;
// 	int		count;
// 	int		min;

// 	count = 0;
// 	elem = * a_stack;
// 	min = elem->content;
// 	while(elem)
// 	{
// 		if (min > elem->content)
// 			return (count);
// 		count++;
// 		elem = elem->next;
// 	}
// 	return (-1);
// }

// void	ft_push_swap(t_list **a_stack, t_list **b_stack, int argc)
// {
// 	int		index;

// 	while (1)
// 	{
// 		index = sort(a_stack);
// 		if (index == -1)
// 			break ;
// 		ft_
// 	}
// }

int	main(int argc, char **argv)
{
	t_list	**a_stack;
	t_list	**b_stack;
	// void	(*put)(int, int)=ft_putnbr_fd;

	a_stack = validate(argc, argv);
	b_stack = (t_list **)malloc(sizeof(t_list *) * (argc - 1));
	if (!b_stack)
		exit(0);
	*b_stack = NULL;
	// ft_push_swap(a_stack, b_stack, argc - 1);



	// op_s(a_stack, "sa");
	// ft_lstiter(a_stack, put);
	// ft_putstr_fd("\n", 1);

	// op_p(b_stack, a_stack, "pb");
	// op_p(b_stack, a_stack, "pb");
	// ft_lstiter(a_stack, put);
	// ft_putstr_fd("\n", 1);
	// ft_lstiter(b_stack, put);
	// ft_putstr_fd("\n", 1);

	// op_r(a_stack, "ra");
	// ft_lstiter(a_stack, put);
	// ft_putstr_fd("\n", 1);

	// op_r(b_stack, "rb");
	// ft_lstiter(b_stack, put);
	// ft_putstr_fd("\n", 1);

	// op_r_r(a_stack, "rra");
	// ft_lstiter(a_stack, put);
	// ft_putstr_fd("\n", 1);

	// op_r_r(b_stack, "rrb");
	// ft_lstiter(b_stack, put);
	// ft_putstr_fd("\n", 1);
	
	
	
	
	// ft_lstiter(*a_stack, put);
	// ft_lstiter(*b_stack, put);


	ft_lstclear(a_stack, NULL);
	// ft_lstclear(b_stack, NULL);
	// while (1)
	// 	;
	return (0);
}
