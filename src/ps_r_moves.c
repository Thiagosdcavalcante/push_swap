/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_r_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:47:14 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/05 21:15:13 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(int c, t_ps_list **stack)
{
	t_ps_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	if (!(*stack)->next->next)
	{
		if (c == 2)
			move_sb(*stack);
		else if (c == 1)
			move_sa(*stack);
	}
	else
	{
		last = (*stack)->next;
		while (last->next)
			last = last->next;
		last->next = *stack;
		*stack = (*stack)->next;
		last->next->next = NULL;
		if (c == 2)
			write (1, "rb\n", 3);
		else if (c == 1)
			write (1, "ra\n", 3);
	}
}

void	move_rr(t_stacks *stack)
{
	rotate(1, &stack->stack_a);
	rotate(2, &stack->stack_b);
   	write (1, "rr\n", 3);
}
