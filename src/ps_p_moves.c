/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:50:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/23 16:42:26 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_pa(t_stacks *stack)
{
	t_ps_list	*temp;

	if (!stack->stack_b)
		return ;
	temp = stack->stack_b;
	stack->stack_b = stack->stack_b->next;
	temp->next = stack->stack_a;
	stack->stack_a = temp;
	stack->stack_b->prev = NULL;
	write (1, "PA\n", 3);
}

void	move_pb(t_stacks *stack)
{
	t_ps_list	*temp;

	if (!stack->stack_b)
		return ;
	temp = stack->stack_a;
	stack->stack_a = stack->stack_a->next;
	temp->next = stack->stack_b;
	stack->stack_b = temp;
	stack->stack_a->prev = NULL;
	write (1, "PB\n", 3);
}
