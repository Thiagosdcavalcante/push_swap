/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:50:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/25 11:24:45 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_pa(t_ps_list *node, t_stacks *stk)
{
	if (!stk->stack_b)
		return ;
	stk->stack_b = stk->stack_b->next;
	stk->stack_b->prev = NULL;
	node->next = stk->stack_a;
	stk->stack_a = node;
	write (1, "PA\n", 3);
}

void	move_pb(t_ps_list *node, t_stacks *stk)
{
	if (!stk->stack_a)
		return ;
	stk->stack_a = stk->stack_a->next;
	stk->stack_a->prev = NULL;
	node->next = stk->stack_b;
	stk->stack_b = node;
	write (1, "PB\n", 3);
}
