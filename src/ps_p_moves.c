/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:50:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/27 14:51:29 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_pa(t_ps_list *node, t_stacks *stk)
{
	t_ps_list	*temp;

	if (!stk->stack_b)
		return ;
	temp = stk->stack_b;
	while (temp && temp->next && (temp->numb != node->next->numb))
		temp = temp->next;
	temp->prev = NULL;
	stk->stack_b = temp;
	node->prev = NULL;
	node->next = stk->stack_a;
	stk->stack_a = node;
	write (1, "PA\n", 3);
}

void	move_pb(t_ps_list *node, t_stacks *stk)
{
	t_ps_list	*temp;

	if (!stk->stack_a)
		return ;
	temp = stk->stack_a;
	while (temp && temp->next && (temp->numb != node->next->numb))
		temp = temp->next;
	temp->prev = NULL;
	stk->stack_a = temp;
	node->prev = NULL;
	node->next = stk->stack_b;
	stk->stack_b = node;
	write (1, "PB\n", 3);
}
