/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:50:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/08 16:15:55 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_pa(t_stacks **stk)
{
		t_ps_list	*tmp;

	if (!(*stk)->stack_b)
		return ;
	tmp =(*stk)->stack_b;
	(*stk)->stack_b = (*stk)->stack_b->next;
	if ((*stk)->stack_a == NULL)
	{
		(*stk)->stack_a = tmp;
		tmp->next = NULL;
	}
	else
		tmp->next = (*stk)->stack_a;
	(*stk)->stack_a = tmp;
	put_sup(stk);
	write (1, "pa\n", 3);
}

void	move_pb(t_stacks **stk)
{
	t_ps_list	*tmp;

	if (!(*stk)->stack_a)
		return ;
	tmp =(*stk)->stack_a;
	(*stk)->stack_a = (*stk)->stack_a->next;
	if ((*stk)->stack_b == NULL)
	{
		(*stk)->stack_b = tmp;
		tmp->next = NULL;
	}
	else
		tmp->next = (*stk)->stack_b;
	(*stk)->stack_b = tmp;
	put_sup(stk);
	write (1, "pb\n", 3);
}
