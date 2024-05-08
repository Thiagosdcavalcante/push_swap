/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:12:17 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/08 14:39:52 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_distance(t_ps_list **to_find, int target)
{
	t_ps_list	*search;
	int	i;
	int j;

	i = 0;
	j = 0;
	search = (*to_find);
	while (search->numb != target)
	{
		i++;
		search = search->next;
	}
	while (search->next)
	{
		j++;
		search = search->next;
	}
	return (i - (j + 1));
}

void	rb_or_rrb(t_ps_list *lst, int target)
{
	if (find_distance(&lst, target) >= 0)
		move_rrb(&lst);
	else
	    rotate(2, &lst);
}


static int	rrr_with_ss(t_stacks *stk, int value)
{
	if ((stk->stack_a->numb < stk->pivot)
	&& (stk->stack_a->numb > stk->sup.end_a->numb)
	&& (stk->stack_a->numb < stk->stack_a->next->numb))
	{
		if ((stk->stack_b->numb > stk->sup.end_b->numb)
			&& (stk->stack_b->next->numb != value))
		{
			move_rrr(stk);
			move_ss(stk);
		}
		put_sup(stk);
		return (1);
	}
	return (0);
}

static int	ss_or_sa(t_stacks *stk, int value)
{
	if ((stk->stack_a->numb < stk->pivot)
		&& (stk->stack_a->next->numb < stk->stack_a->numb)
		&& (stk->stack_a->numb < stk->sup.end_a->numb))
	{
		if ((stk->stack_a->numb != value && stk->sup.end_b)
			&& (stk->stack_b->numb > stk->stack_b->next->numb)
			&& (stk->stack_b->numb < stk->sup.end_b->numb))
			move_ss(stk);
		else
			move_sa(stk->stack_a);
		put_sup(stk);
		return (1);
	}
	put_sup(stk);
	return (0);
}

int	is_possible(t_stacks *stks, int value)
{
	if (!stks->stack_a->next || !stks->stack_b->next)
		return (0);
	if (ss_or_sa(stks, value) == 1)
	{
		put_sup(stks);
		return (1);
	}
	else if (rrr_with_ss(stks, value) == 1)
	{
		put_sup(stks);
		return (1);
	}
	return (0);
}
