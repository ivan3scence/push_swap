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
			if (ft_isdigit(argv[i][j++]) == 0)
				error_ps(NULL, NULL, 1);
		}
	}
}

static void	check_int(int argc, char **argv)
{
	char	minus;
	int		i;

	minus = 0;
	while (--argc > 0)
	{
		i = -1;
		if (argv[argc][++i] == '+' || argv[argc][i] == '-')
		{
			if (argv[argc][i] == '-')
				minus = 1;
			++i;
		}
		if (ft_strlen(&argv[argc][i]) > 10
			|| (!minus && ft_strlen(&argv[argc][i]) == 10
				&& ft_strncmp("2147483647", &argv[argc][i], 12) < 0)
			|| (minus && ft_strlen(&argv[argc][i]) == 10
				&& ft_strncmp("2147483648", &argv[argc][i], 12) < 0))
			error_ps(NULL, NULL, 1);
	}
}	

static void	check_dups(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;

	argc--;
	j = 0;
	while (argc > ++j)
	{
		i = j;
		while (++i <= argc)
		{
			n = -1;
			while (argv[i][++n] && argv[j][n])
			{
				if (argv[i][n] != argv[j][n])
					break ;
			}
			if (!argv[i][n] && !argv[j][n])
				error_ps(NULL, NULL, 1);
		}
	}
}

t_list	**validate(int argc, char **argv)
{
	t_list	**a_stack;
	int		i;

	i = 0;
	check_digits(argc, argv);
	check_int(argc, argv);
	check_dups(argc, argv);
	a_stack = (t_list **)malloc(sizeof(t_list *) * (argc - 1));
	if (!a_stack)
		error_ps(NULL, NULL, 0);
	*a_stack = NULL;
	while (argc > ++i)
		ft_lstadd_back(a_stack, ft_lstnew(ft_atoi(argv[i])));
	return (a_stack);
}
