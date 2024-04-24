/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:59:27 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/23 16:41:48 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_rra(t_stacks *stack)
{
   	t_ps_list	*temp1;
   	t_ps_list	*temp2;

   	temp1 = stack->stack_a;
	while (temp1->next)
		temp1 = temp1->next;
	temp2 = stack->stack_a;
	while (temp2->numb != temp1->numb)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->prev = NULL;
	while (temp2->prev)
		temp2 = temp2->prev;
	temp2->prev = temp1;
	temp1->next = temp2;
	stack->stack_a = temp1;
   	write (1, "RRA\n", 3);
}

void	move_rrb(t_stacks *stack)
{
   	t_ps_list	*temp1;
   	t_ps_list	*temp2;

   	temp1 = stack->stack_b;
	while (temp1->next)
		temp1 = temp1->next;
	temp2 = stack->stack_b;
	while (temp2->numb != temp1->numb)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->prev = NULL;
	while (temp2->prev)
		temp2 = temp2->prev;
	temp2->prev = temp1;
	temp1->next = temp2;
	stack->stack_b = temp1;
   	write (1, "RRB\n", 3);
}

void	move_rrr(t_stacks *stack)
{
	move_rra(stack);
	move_rrb(stack);
   	write (1, "RRR\n", 3);
}
