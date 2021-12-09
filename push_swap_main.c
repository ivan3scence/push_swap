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
	int		i;

	i = 0;
	check_digits(argc, argv);
	check_int(argc, argv);
	check_dups(argc, argv);
	a_stack = (t_list **)malloc(sizeof(t_list *) * (argc - 1));
	if (!a_stack)
		exit(0);
	*a_stack = NULL;	
	while (argc > ++i)
		ft_lstadd_back(a_stack, ft_lstnew(ft_atoi(argv[i])));
	return (a_stack);
}



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

int	ft_check_sort(t_list **stack)
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
	return (-1);
}

void	ft_sort_three(t_list **stack, char *str)
{
	int	index;
	t_list	*elem2;
	t_list	*elem3;

	index = ft_check_sort(stack);
	if (index == -1)
		return ;
	elem2 = (*stack)->next;
	elem3 = elem2->next;
	if ((index == 0 && elem3->content < elem2->content)
		|| (index == 1 && elem3->content > (*stack)->content))
		op_s(stack, str);
	if ((*stack)->content > elem2->content && (*stack)->content < elem3->content)
		return (op_s(stack, str));
	if ((*stack)->content > elem2->content && (*stack)->content > elem3->content)
		return (op_r(stack, str));
	return (op_r_r(stack, str));
}


void	ft_sort_two(t_list **a_stack, char *str)
{
	if ((*a_stack)->content < (*a_stack)->next->content)
		return ;
	return (op_s(a_stack, str));
}
/*
void	ft_sort_five(t_list **a_stack, t_list **b_stack, int argc)
{
	while (argc-- > 5)
		op_p(b_stack, a_stack, "b");
	ft_sort_three(a_stack, "b");
	if (((*a_stack)->content < (*b_stack)->content) && ((*a_stack)->next->next->content < (*b_stack)->content))
	{
		op_p(a_stack, b_stack, "a");
		op_r(a_stack, "a");
	}
	else if (((*a_stack)->content < (*b_stack)->content)
		&& ((*a_stack)->next->next->content > (*b_stack)->content)
		&& ((*a_stack)->next->content > (*b_stack)->content))
	{
		op_p(a_stack, b_stack, "a");
		op_s(a_stack, "a");
	}
	else if (((*a_stack)->content < (*b_stack)->content)
		&& ((*a_stack)->next->next->content > (*b_stack)->content)
		&& ((*a_stack)->next->content < (*b_stack)->content))
	{
		op_p(a_stack, b_stack, "a");
		op_s(a_stack, "a");
	}

}

void	ft_pop(t_list **stack_from, t_list **stack_to, int median, int size)
{
	int	count_of_poped;

	count_of_poped = 0;
	while (count_of_poped < size / 2)
	{
		if ((*stack_from)->content < median)
		{
			op_p(stack_to, stack_from, "b");
			count_of_poped++;
		}
		else
			op_r_r(stack_from, "a");
	}
}

void	ft_try_second_part(t_list **a_stack, t_list **b_stack, int quantity)
{

}

void	ft_try(t_list **a_stack, t_list **b_stack, int quantity)
{
	int	size;

	size = ft_lstsize(*a_stack);
	while (size > 2)
	{
		ft_pop(a_stack, b_stack, median(a_stack, size), size);
		size = ft_lstsize(*a_stack);
	}
	ft_sort_two(a_stack, "a");
	return (ft_try_second_part(a_stack, b_stack, quantity));
}
*/

void	swap(int *p, int *q)
{
	int	t;
   
	t = *p; 
	*p = *q; 
	*q = t;
}

int	*ft_array(t_list **stack, int n)
{
	int		*a;
	t_list	*elem;
	int		i;

	elem = *stack;
	i = -1;
	a = (int *)malloc(sizeof(int) * n);
	if (!a)
		return (0);
	while (n--)
	{
		a[++i] = elem->content;
		elem = elem->next;
	}
	return (a);
}
/*
int	median(t_list **stack, int n)
{ 
	int	*a;
	int	i;
	int	j;
	int	temp;

	a = ft_array(stack, n);
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - i - 1)
		{
			if(a[j] > a[j+1])
				swap(&a[j],&a[j + 1]);
		}
	}
	return (a[n / 2]);
}

int	ft_push_median(t_list **a_stack, t_list **b_stack, int quantity, int median)
{

	return median;
*/


int	ft_min(t_list **stack)
{
	t_list	*elem;
	int		min;
	int		count;
	int		c;

	count = 0;
	elem = *stack;
	min = 2147483647;
	if (!elem)
		return (-1);
	while (elem && ++count)
	{
		if (elem->content < min)
		{
			min = elem->content;
			c = count - 1;
		}
		elem = elem->next;
	}
	return (c);
}
/*
void	ft_big_sort(t_list **a_stack, t_list **b_stack, int quantity)
{
	t_list	*elem;
	long int		*max;
	long int 	*min;
	int		mid;

	elem = *a_stack;
	ft_maxmin(a_stack, max, min);
	mid = ft_push_median(a_stack, b_stack, quantity, median(a_stack, quantity));
	while (elem)
	{
		if (elem->content != max && elem->content != min && elem->content < mid)
			op_p(b_stack, a_stack, "b");
		else if (elem->content != max && elem->content != min && elem->content > mid)
		{
			op_r(b_stack, "b");
			op_p(b_stack, a_stack, "b");
		}
		elem = elem->next;
	}
	ft_second_part(a_stack, b_stack, quantity);
}
*/



// void	ft_sort_hundred(t_list **a_stack, t_list **b_stack, int argc)
// {
// 	return ;
// }
// void	ft_sort_five_hundred(t_list **a_stack, t_list **b_stack, int argc)
// {
// 	return ;
// }

void	push_swap_min(t_list **a_stack, t_list ** b_stack)
{
	int	min;
	int	lstsize;

	while (*a_stack)
	{
		lstsize = ft_lstsize(*a_stack);
		min = ft_min(a_stack);
		if (lstsize > 1 && (min) * 2 > lstsize)
		{
			while (min++ < lstsize)
				op_r_r(a_stack, "a");
		}
		else if (lstsize > 1)
		{
			while (min-- > 0)
				op_r(a_stack, "a");
		}
		op_p(b_stack, a_stack, "b");
	}
	while (*b_stack)
		op_p(a_stack, b_stack, "a");
}

int	main(int argc, char **argv)
{
	t_list	**a_stack;
	t_list	**b_stack;
	// void	(*put)(int, int)=ft_putnbr_fd;

	if (argc < 3)
		return (0);
	a_stack = validate(argc, argv);
	b_stack = (t_list **)malloc(sizeof(t_list *) * (argc - 1));
	if (!b_stack)
		exit(0);
	*b_stack = NULL;
	// ft_lstiter(a_stack, put);
	// ft_putstr_fd("\n", 1);
	push_swap_min(a_stack, b_stack);
	// if (argc == 3)
	// 	ft_sort_two(a_stack, "a");
	// if (argc == 4)
	// 	ft_sort_three(a_stack, "a");
	// if (argc < 7)
	// 	ft_sort_five(a_stack, b_stack, argc);
	// if (argc < 102 && argc > 4)
	// 	ft_sort_hundered(a_stack, b_stack, argc);
	// if (argc > 101 && argc < 502)
	// 	ft_sort_five_hundered(a_stack, b_stack, argc);
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
