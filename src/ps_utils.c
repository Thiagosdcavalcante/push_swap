/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:26:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/08 16:41:35 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_target(t_ps_list *lst)
{
	int	target;

	target = 0;
	if (lst)
	{
		target = lst->numb;
		while (lst)
		{
			if (lst->numb > target)
				target = lst->numb;
			lst = lst->next;
		}
	}
	return (target);
}

void	b_back_to_a(t_stacks *stk)
{
	int	value;

	value = find_target(stk->stack_b);
	while (stk->stack_b)
	{
		if (stk->stack_b->next && (value == stk->stack_b->next->numb))
		{
			move_sb(stk->stack_b, stk);
			move_pa(&stk);
			value = find_target(stk->stack_b);
		}
		else if (stk->stack_b->next && stk->stack_b->numb == value)
		{
			move_pa(&stk);
			value = find_target(stk->stack_b);
		}
		else if (!stk->stack_b->next)
			move_pa(&stk);
		else
			move_rrb(&stk->stack_b, stk);
	}
	if (stk->stack_b)
		move_pa(&stk);
	stk->stack_b = NULL;
}

void	ps_mvs_conditions(t_stacks **stks)
{
	if (!(*stks)->stack_b->next)
		return ;
	else if ((*stks)->stack_b->numb < (*stks)->stack_b->next->numb)
		move_sb((*stks)->stack_b, (*stks));
	else if ((*stks)->sup.head_b
		&& (*stks)->stack_b->numb < (*stks)->sup.head_b->numb)
		rotate(2, &(*stks)->stack_b, (*stks));	
}
