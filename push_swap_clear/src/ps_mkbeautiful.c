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

static int	*ft_array(t_list **stack, int n)
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

static void	swap(int *p, int *q)
{
	int	t;

	t = *p;
	*p = *q;
	*q = t;
}

static int	*sort_array(t_list **stack, int n)
{
	int	*a;
	int	i;
	int	j;

	a = ft_array(stack, n);
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - i - 1)
		{
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}
	return (a);
}

static int	change_content(t_list **stack, int *sarray, int len)
{
	t_list	*elem;
	int		i;

	elem = *stack;
	while (elem)
	{
		i = -1;
		while (++i < len)
		{
			if (sarray[i] == elem->content)
				break ;
		}
		if (i == len)
			return (0);
		elem->content = i;
		elem = elem->next;
	}
	return (1);
}

void	make_beautiful(t_list **stack, t_list **sec_stack, int len)
{
	int	*sorted_array;

	sorted_array = sort_array(stack, len);
	if (change_content(stack, sorted_array, len) == 0)
		error_ps(stack, sec_stack, 4);
	free(sorted_array);
}
