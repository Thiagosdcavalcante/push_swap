/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:59:27 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/05 21:07:39 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_rra(t_ps_list **stack_a)
{
	t_ps_list	*temp1;
	t_ps_list	*temp2;
	
	if (!(*stack_a))
		return ;
	temp1 = (*stack_a);
	while (temp1->next->next != NULL)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp2->next = (*stack_a);
	temp1->next = NULL;
	(*stack_a) = temp2;
	write(1, "rra\n", 4);
}

void	move_rrb(t_ps_list **stack_b)
{
	t_ps_list	*temp1;
	t_ps_list	*temp2;
	
	if (!(*stack_b))
		return ;
	temp1 = (*stack_b);
	while (temp1->next->next != NULL)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp2->next = (*stack_b);
	temp1->next = NULL;
	(*stack_b) = temp2;
   	write (1, "rrb\n", 4);
}

void	move_rrr(t_stacks *stack)
{
	move_rra(&stack->stack_a);
	move_rrb(&stack->stack_b);
   	write (1, "rrr\n", 3);
}
