/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:26:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/14 16:30:13 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_size(t_stacks *stk)
{
	int			size;
	t_ps_list	*lst;

	size = 1;
	lst = stk->stack_a;
	while (lst->next)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	parse_stack(t_stacks *stk)
{
	int	size;

	size = find_size(stk);
	if (size <= 5)
		parse_5(stk, size);
	else
		random_parse(stk);
}

static int	find_last_target(t_ps_list *lst, int min)
{
	int	target;

	target = min;
	if (lst)
	{
		while (lst)
		{
			if (lst->numb > target)
				target = lst->numb;
			lst = lst->next;
		}
	}
	return (target);
}

static int	moves_to_finish(t_ps_list *lst, int target)
{
	t_ps_list	*srch;
	int			i;
	int			j;

	srch = lst;
	i = 0;
	j = 0;
	while (srch->next && srch->numb != target)
	{
		i++;
		srch = srch->next;
	}
	while (srch->next)
	{
		j++;
		srch = srch->next;
	}
	return (i - (j + 1));
}

void	end_sort(t_stacks *stk)
{
	int	target;

	while (stk->stack_b)
	{
		target = find_last_target(stk->stack_b, stk->minim);
		if (stk->stack_b->numb == target)
		{
			move_pa(&stk);
			if (stk->stack_a->numb > stk->stack_a->next->numb)
				move_sa(stk->stack_a, stk);
		}
		else if (moves_to_finish(stk->stack_b, target) >= 0
			&& stk->stack_b->next)
			while (stk->stack_b->numb != target && stk->stack_b->next)
				move_rrb(&stk->stack_b, stk);
		else if (moves_to_finish(stk->stack_b, target) < 0
			&& stk->stack_b->next)
			while (stk->stack_b->numb != target && stk->stack_b->next)
				rotate(2, &stk->stack_b, stk);
		else
			move_pa(&stk);
	}
	stk->stack_b = NULL;
}
