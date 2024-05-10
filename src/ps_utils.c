/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:26:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/09 19:33:22 by tsantana         ###   ########.fr       */
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

	while (stk->stack_b)
	{
		value = find_target(stk->stack_b);
		if (!stk->stack_b->next || (stk->stack_b->next
		   && stk->stack_b->numb == value))
			move_pa(&stk);
		else if (stk->stack_b->next && (value == stk->stack_b->next->numb))
			move_sb(stk->stack_b, stk);
		else if (find_distance(&stk->stack_b, value) > 0)
			move_rrb(&stk->stack_b, stk);
		else
			rotate(2, &stk->stack_b, stk);
	}
	stk->stack_b = NULL;
}
