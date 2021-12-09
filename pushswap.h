/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:40:07 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/23 13:44:47 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

void	op_s(t_list **stack, char *str);
void	op_ss(t_list **a, t_list **b);
void	op_p(t_list **stack_to, t_list **stack_from, char *str);
void	op_r(t_list **stack, char *str);
void	op_rr(t_list **a, t_list **b);
void	ft_lstprev(t_list **stack, t_list *elem);
void	op_r_r(t_list **stack, char *str);
void	op_rrr(t_list **a, t_list **b);
#endif
