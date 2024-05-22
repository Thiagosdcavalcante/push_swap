/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:02:19 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/14 16:24:31 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	minor_moves(t_ps_list *lst, int pvt, int size)
{
	t_ps_list	*srch;
	int			i;

	srch = lst;
	i = 0;
	while (srch && srch->numb != pvt)
	{
		i++;
		srch = srch->next;
	}
	return (size - i);
}

static int	find_minor_five(t_stacks *stk)
{
	t_ps_list	*a;
	int			result;

	a = stk->stack_a;
	result = stk->maxm;
	while (a)
	{
		if (a->numb < result)
			result = a->numb;
		a = a->next;
	}
	return (result);
}

void	solve_three(t_stacks *stk)
{
	if (stk->stack_a->numb < stk->stack_a->next->numb
		&& stk->stack_a->numb > stk->stack_a->next->next->numb)
		move_rra(&stk->stack_a, stk);
	else if (stk->stack_a->numb > stk->stack_a->next->numb
		&& stk->stack_a->next->numb > stk->stack_a->next->next->numb)
	{
		move_sa(stk->stack_a, stk);
		move_rra(&stk->stack_a, stk);
	}
	else if (stk->stack_a->numb < stk->stack_a->next->numb
		&& stk->stack_a->next->numb > stk->stack_a->next->next->numb
		&& stk->stack_a->numb < stk->stack_a->next->next->numb)
	{
		move_rra(&stk->stack_a, stk);
		move_sa(stk->stack_a, stk);
	}
	else if (stk->stack_a->numb > stk->stack_a->next->numb
		&& stk->stack_a->numb < stk->stack_a->next->next->numb)
		move_sa(stk->stack_a, stk);
	else if (stk->stack_a->numb > stk->stack_a->next->next->numb
		&& stk->stack_a->next->numb < stk->stack_a->next->next->numb)
		rotate(1, &stk->stack_a, stk);
}

static void	four_or_five(t_stacks *stk, int index)
{
	int	minor;

	minor = stk->minim;
	if (index == 4)
		sort_four(stk, minor);
	else if (index == 5)
	{
		if (stk->stack_a->numb == minor)
			move_pb(&stk);
		else
			four_five_utils(stk, minor, index);
		minor = find_minor_five(stk);
		while (stk->stack_a->numb != minor)
			move_rra(&stk->stack_a, stk);
		move_pb(&stk);
		solve_three(stk);
		move_pa(&stk);
		move_pa(&stk);
	}
}

void	parse_5(t_stacks *stk, int size)
{
	if (size == 3)
		solve_three(stk);
	else if (size >= 4 && size <= 5)
		four_or_five(stk, size);
	else
		if (stk->stack_a->next && stk->stack_a->numb > stk->stack_a->next->numb)
			move_sa(stk->stack_a, stk);
}
