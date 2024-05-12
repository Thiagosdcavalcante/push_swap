/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:30:53 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/09 22:07:03 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	test_moves(t_ps_list **a, t_ps_list **b, int pvt, t_stacks *stk)
{
	if (!(*b) || !(*b)->next)
		return ;
	if (stk->sup.end_b && ((stk->sup.end_a->numb < pvt) && ((*a)->numb < pvt))
		&& ((*b)->numb < stk->sup.end_b->numb)
		&& ((*a)->numb < stk->sup.end_a->numb))
	{
		if (((*a)->numb > (*a)->next->numb) && ((*b)->numb > (*b)->next->numb))
			move_rrr(stk);
		else
		{
			move_ss(stk);
			move_rrr(stk);
		}
		move_ss(stk);
	}
	if (((*a)->numb < (*a)->next->numb) && (stk->sup.end_a->numb < (*a)->next->numb)
		&& ((*a)->numb < stk->sup.end_a->numb))
		if (((*b)->numb < (*b)->next->numb)
			&& (stk->sup.end_b->numb < (*b)->next->numb)
			&& ((*b)->numb) < (*b)->next->numb)
			move_rrr(stk);
	if ((*a)->numb < pvt && ((*a)->next->numb < pvt)
		&& ((*a)->numb < (*a)->next->numb))
		if ((*b)->numb < (*b)->next->numb)
			move_ss(stk);
}
