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

void	error_ps(t_list **a_stack, t_list **b_stack, int flag)
{
	if (flag == 1)
		ft_putstr_fd("Error\n", 2);
	if (a_stack && !*a_stack)
		free(a_stack);
	else if (a_stack)
		ft_lstclear(a_stack, NULL);
	if (b_stack && !*b_stack)
		free(b_stack);
	else if (b_stack)
		ft_lstclear(b_stack, NULL);
	exit(1);
}

int	is_sorted(t_list **stack)
{
	t_list	*elem;
	t_list	*check;

	elem = *stack;
	if (!elem)
		return (1);
	while (elem)
	{
		check = elem->next;
		while (check)
		{
			if (elem->content > check->content)
				return (0);
			check = check->next;
		}
		elem = elem->next;
	}
	return (1);
}

static void	clear_lists(t_list **a_stack, t_list **b_stack)
{
	if (a_stack)
	{
		if (*a_stack)
			ft_lstclear(a_stack, NULL);
		free(a_stack);
		a_stack = NULL;
	}
	if (b_stack)
	{
		if (*b_stack)
			ft_lstclear(b_stack, NULL);
		free(b_stack);
		b_stack = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_list	**a_stack;
	t_list	**b_stack;

	if (argc < 3)
		return (0);
	a_stack = validate(argc, argv);
	if (is_sorted(a_stack) == 1)
		error_ps(a_stack, NULL, 2);
	b_stack = (t_list **)malloc(sizeof(t_list *) * (argc - 1));
	if (!b_stack)
		error_ps(a_stack, b_stack, 3);
	*b_stack = NULL;
	make_beautiful(a_stack, b_stack, argc - 1);
	if (argc == 3)
		ft_sort_two(a_stack, "a");
	else if (argc == 4)
		ft_sort_three(a_stack, b_stack, "a");
	else if (argc < 7)
		ft_sort_five(a_stack, b_stack, argc - 1);
	else
		push_radix(a_stack, b_stack, argc - 1);
	// ft_lstiter(a_stack, &ft_putnbr_fd);
	// ft_putchar_fd('\n', 1);
	// ft_lstiter(b_stack, &ft_putnbr_fd);
	clear_lists(a_stack, b_stack);
	// char *s=malloc(1488);
	// s[0] = 'g';
	return (0);
}
