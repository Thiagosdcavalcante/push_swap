/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:02:19 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/10 15:11:30 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int   find_bigger(t_ps_list *lst)
{
	int bigger;
	t_ps_list *find;

	bigger = 1;
	find = lst;
	while (find)
	{
		if (find->numb > bigger)
			bigger = find->numb;
		find = find->next;
	}
	return (bigger);
}

static void parse_back(t_stacks  *stk)
{
	int bigger;

	while (stk->stack_b)
   	{
		bigger = find_bigger(stk->stack_b);
        while (stk->stack_b->numb != bigger)
			rotate(2, &stk->stack_b, stk);
		move_pa(&stk);
	}
	stk->stack_b = NULL;
}

static int  find_minor(t_ps_list *lst)
{
	t_ps_list *find;
	int result;

	find = lst;
	result = lst->numb;
	while (find)
	{
		if (find->numb < result)
			result = find->numb;
		find = find->next;
	}
	return (result);
}

void	parse_5(t_stacks *stk)
{
	int   trgt;
	
	while (stk->stack_a && stk->stack_a->next)
	{
		trgt = find_minor(stk->stack_a);
		while (stk->stack_a->numb != trgt)
		{
			if (stk->stack_a->numb < stk->stack_a->next->numb)
				move_sa(stk->stack_a, stk);
			move_rra(&stk->stack_a, stk);
		}
		move_pb(&stk);
	}
	if (stk->stack_a->numb == stk->maxm)
		parse_back(stk);
	else
		move_pa(&stk);
}

