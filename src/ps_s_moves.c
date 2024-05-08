/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_s_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:28:55 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/08 16:23:22 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_sa(t_ps_list *stack_a, t_stacks *stk)
{
	int	tmp;

	tmp = 0;
	tmp = stack_a->numb;
	stack_a->numb = stack_a->next->numb;
	stack_a->next->numb = tmp;
	put_sup(&stk);
	write (1, "sa\n", 3);
}

void	move_sb(t_ps_list *stack_b, t_stacks *stk)
{
	int	tmp;

	tmp = 0;
	tmp = stack_b->numb;
	stack_b->numb = stack_b->next->numb;
	stack_b->next->numb = tmp;
	put_sup(&stk);
	write (1, "sb\n", 3);
}

void	move_ss(t_stacks *stack)
{
	move_sa(stack->stack_a, stack);
	move_sb(stack->stack_b, stack);
	write (1, "ss\n", 3);
}
