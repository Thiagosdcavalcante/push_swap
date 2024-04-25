/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:59:27 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/25 10:23:54 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_rra(t_ps_list *stack_a)
{
   	t_ps_list	*temp1;
   	t_ps_list	*temp2;
	
	temp1 = stack_a;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	temp2 = temp1;
	temp2 ->prev = NULL;
	temp1 = temp1->prev;
	temp1->next = NULL;
	temp2 = stack_a;
   	write (1, "RRA\n", 3);
}

void	move_rrb(t_ps_list *stack_b)
{
   	t_ps_list	*temp1;
   	t_ps_list	*temp2;
	
	temp1 = stack_b;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	temp2 = temp1;
	temp2 ->prev = NULL;
	temp1 = temp1->prev;
	temp1->next = NULL;
	temp2 = stack_b;
   	write (1, "RRA\n", 3);
   	write (1, "RRB\n", 3);
}

void	move_rrr(t_stacks *stack)
{
	move_rra(stack->stack_a);
	move_rrb(stack->stack_b);
   	write (1, "RRR\n", 3);
}
