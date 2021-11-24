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

	i = -1;
	check_digits(argc, argv);
	check_int(argc, argv);
	check_dups(argc, argv);
	// elem = ft_lstnew(ft_atoi(argv[1]));
	// a_stack = &elem;
	a_stack = (t_list **)malloc(sizeof(t_list *) * (argc - 1));
	// if (!a_stack)
	// {
	// 	ft_putstr_fd("ne sdelalsya elem", 1);
	// 	exit(0);
	// }
	
	while (argc - 1 > ++i)
		ft_lstadd_back(a_stack, ft_lstnew(ft_atoi(argv[i + 1])));
	// ft_putnbr_fd((*a_stack)->content, 1);
	return (a_stack);
}

void	op_s(t_list **stack, char *str)
{
	// t_list	*first;
	// int	tmp;

	if (!(stack && *stack && (*stack)->next))
		return ;
	// first = *stack;
	// stack = &(first->next);
	// first->next = (*stack)->next;
	// (*stack)->next = first;
	// first = NULL;

	// tmp = (*stack)->content;
	// (*stack)->content = (*stack)->next->content;
	// (*stack)->next->content = tmp;
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
	if (!(stack_from && (*stack_from)))
		return ;
	ft_lstadd_front(stack_to, *stack_from);
	stack_from = &((*stack_from)->next);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}

void	op_r(t_list **stack, char *str)
{
	t_list	*tmp;

	if (!(stack && *stack))
		return ;
	tmp = *stack;
	stack = &(tmp->next);
	ft_lstadd_back(stack, tmp);
	tmp->next = NULL;
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

void	op_r_r(t_list **stack, char *str)
{
	if (!(stack && *stack))
		return ;
	ft_lstadd_front(stack, ft_lstlast(*stack));
	ft_lstdelone(ft_lstlast(*stack), NULL);
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



int	main(int argc, char **argv)
{
	t_list	**a_stack;
	// t_list	**b_stack;
	void	(*put)(int, int)=ft_putnbr_fd;

	a_stack = validate(argc, argv);
	// ft_putnbr_fd((*a_stack)->content, 1);
	// lst_print(a_stack);
	// b_stack = NULL;
	op_s(a_stack, "sa");
	ft_lstiter(a_stack, put);
	// ft_lstiter(a_stack, put);
	// ft_lstiter(a_stack, put);
	// ft_lstiter(a_stack, put);
	// ft_lstiter(a_stack, put);
	// ft_lstiter(a_stack, put);
	// ft_lstiter(a_stack, put);
	// op_p(a_stack, b_stack, NULL);
	
	
	
	
	
	// ft_lstiter(*a_stack, put);
	// ft_lstiter(*b_stack, put);


	ft_lstclear(a_stack, NULL);
	// ft_lstclear(b_stack, NULL);
	return (0);
}
