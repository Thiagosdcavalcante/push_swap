/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_r_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:47:14 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/25 11:24:51 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_ra(t_ps_list *stack_a)
{
   	t_ps_list	*temp1;
   	t_ps_list	*temp2;

   	temp1 = stack_a;
   	temp2 = stack_a;
	temp2 = temp2->next;
	temp2->prev = NULL;
	temp1->next = NULL;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp1;
	temp1->prev = temp2;
	stack_a = temp2;
   	write (1, "RA\n", 3);
}

void	move_rb(t_ps_list *stack_b)
{
   	t_ps_list	*temp1;
   	t_ps_list	*temp2;

   	temp1 = stack_b;
   	temp2 = stack_b;
	temp2 = temp2->next;
	temp2->prev = NULL;
	temp1->next = NULL;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp1;
	temp1->prev = temp2;
	stack_b = temp2;
   	write (1, "RB\n", 3);
}

void	move_rr(t_stacks *stack)
{
	move_ra(stack->stack_a);
	move_rb(stack->stack_b);
   	write (1, "RR\n", 3);
}
