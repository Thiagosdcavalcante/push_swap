/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_s_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:28:55 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/25 11:24:59 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_sa(t_ps_list *stack_a)
{
	t_ps_list	*head;
	t_ps_list	*temp;
	t_ps_list	*temp2;

	head = stack_a->next;
	temp = stack_a;
	temp2 = head->next;
	temp2->prev = temp;
	temp->prev = head;
	head->prev = NULL;
	head->next = temp;
	temp->next = temp2;
	stack_a = head;
	write (1, "SA\n", 3);
}

void	move_sb(t_ps_list *stack_b)
{
	t_ps_list	*head;
	t_ps_list	*temp;
	t_ps_list	*temp2;

	head = stack_b->next;
	temp = stack_b;
	temp2 = head->next;
	temp2->prev = temp;
	temp->prev = head;
	head->prev = NULL;
	head->next = temp;
	temp->next = temp2;
	stack_b = head;
	write (1, "SB\n", 3);
}

void	move_ss(t_stacks *stack)
{
	move_sa(stack->stack_a);
	move_sb(stack->stack_b);
	write (1, "SS\n", 3);
}
