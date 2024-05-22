/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:39:56 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/14 16:24:18 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	four_five_utils(t_stacks *stk, int minor, int index)
{
	if (minor_moves(stk->stack_a, minor, index) < 3)
		while (stk->stack_a->numb != minor)
			move_rra(&stk->stack_a, stk);
	else if (minor_moves(stk->stack_a, minor, index) >= 3)
		while (stk->stack_a->numb != minor)
			rotate(1, &stk->stack_a, stk);
	move_pb(&stk);
}

static void	put_sup_a(t_ps_list *lst, t_sup sup)
{
	t_ps_list	*a;

	if (!lst)
	{
		sup.end_a = NULL;
		sup.head_a = NULL;
	}
	else if (lst && !lst->next)
	{
		sup.end_a = lst;
		sup.head_a = lst;
	}
	else
	{
		a = lst;
		while (a->next)
		{
			if (a->numb > sup.end_a->numb)
				sup.end_a = a;
			a = a->next;
		}
	}
	sup.head_a = lst;
}

static void	put_sup_b(t_stacks **stk)
{
	t_ps_list	*b;

	if ((*stk)->stack_b && !(*stk)->stack_b->next)
	{
		(*stk)->sup.end_b = (*stk)->stack_b;
		(*stk)->sup.head_b = (*stk)->stack_b;
	}
	else
	{
		(*stk)->sup.head_b = (*stk)->stack_b;
		b = (*stk)->stack_b;
		while (b->next)
			b = b->next;
		(*stk)->sup.end_b = b;
	}
}

void	put_sup(t_stacks **stks)
{
	put_sup_a((*stks)->stack_a, (*stks)->sup);
	if ((*stks)->stack_b)
		put_sup_b(stks);
	else
	{
		(*stks)->sup.end_b = NULL;
		(*stks)->sup.head_b = NULL;
	}
}
