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
	while (argc - 1> ++i)
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

static void	check_dups(int argc, int *a_stack)
{
	int	i;
	int	j;

	argc--;
	j = -1;
	while (argc > ++j)
	{
		i = -1;
		while (++i < j)
		{
			if (a_stack[i] == a_stack[j])
			{
				free(a_stack);
				error_ps();
			}
		}
	}
}

static int	*validate(int argc, char **argv)
{
	int	*a_stack;
	int	i;

	i = -1;
	check_digits(argc, argv);
	check_int(argc, argv);
	//ft_putstr_fd(argv[3], 1);
	a_stack = (int *)malloc(sizeof(int) * (argc - 1));
	if (!a_stack)
		exit(0);
	//ft_putstr_fd(argv[3], 1);
	while (argc - 1 > ++i)
		a_stack[i] = ft_atoi(argv[i + 1]);
	check_dups(argc, a_stack);
	return (a_stack);
}

int	main(int argc, char **argv)
{
	int		*a_stack;
	int i=-1;

	a_stack = validate(argc, argv);
	while (argc - 1 > ++i)
		ft_putnbr_fd(a_stack[i], 1);

	
	
	
	return (0);
}
