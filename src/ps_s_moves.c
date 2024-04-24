/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_s_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:28:55 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/23 16:41:28 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_sa(t_stacks *stack)
{
	t_ps_list	*temp;

	temp = stack->stack_a;
	stack->stack_a = stack->stack_a->next;
	temp->next = stack->stack_a->next;
	stack->stack_a->prev = NULL;
	stack->stack_a->next = temp;
	write (1, "SA\n", 3);
}

void	move_sb(t_stacks *stack)
{
	t_ps_list	*temp;

	temp = stack->stack_b;
	stack->stack_b = stack->stack_b->next;
	temp->next = stack->stack_b->next;
	stack->stack_b->prev = NULL;
	stack->stack_b->next = temp;
	write (1, "SB\n", 3);
}

void	move_ss(t_stacks *stack)
{
	move_sa(stack);
	move_sb(stack);
	write (1, "SS\n", 3);
}
