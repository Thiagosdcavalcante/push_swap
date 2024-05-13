/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:12:17 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/13 14:04:37 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	best_moves(t_ps_list *lst, int pvt)
{
	t_ps_list	*srch;
	int			i;
	int			j;

	srch = lst;
	i = 0;
	j = 0;
	if (srch->numb < pvt)
		return (0);
	while (srch && srch->numb >= pvt)
	{
		i++;
		srch = srch->next;
	}
	srch = lst;
	while (srch)
	{
		if(srch->numb < pvt)
		    j = 0;
		else
		    j++;
		srch = srch->next;
	}
	return (i - j);
}

static int   has_minor_target(t_ps_list *lst, int target)
{
	t_ps_list    *find;

	if (!lst || !lst->next)
		return (0);
	find = lst;
	while (find->next)
	{
		if (find->numb < target)
		    return (1);
		find = find->next;
	}
	return (0);
}

static int	loop_minor(int base, t_ps_list *lst, int max)
{
	int	result;

	result = max;
	while (lst->next)
	{
		if (lst->numb > base && lst->numb < result && lst->numb < max)
			result = lst->numb;
		lst = lst->next;
	}
	return (result);
}

static int	find_minor(t_stacks *stk, int min)
{
	int	i;
	int	base;

	i = 0;
	base = min;
	if (!stk->stack_a || !stk->stack_a->next)
		return (0);
	while (i <= 20)
	{
		// ft_printf("i: %d |base %d \n", i, base);
		if (stk->stack_a->next)
			base = loop_minor(base, stk->stack_a, (int)stk->maxm);
		i++;
	}
	return (base);
}

static void	r_or_rr(t_stacks *stk, int target)
{
	if (best_moves(stk->stack_a, target) > 0)
		while (stk->stack_a->numb >= target)
		   move_rra(&stk->stack_a, stk);
	else if (best_moves(stk->stack_a, target) <= 0)
	{
		while (stk->stack_a->numb >= target)
			rotate(1, &stk->stack_a, stk);
	}
}

static void	parse_utils(t_stacks *stk, int target)
{
	while (has_minor_target(stk->stack_a, target) == 1)
	{
		if (stk->stack_a->numb < target)
			move_pb(&stk);
		else
			r_or_rr(stk, target);
	}
}

void	random_parse(t_stacks *stk)
{
	int	target;

	target = find_minor(stk, stk->minim);
	while (stk->stack_a->next)
	{
		if (!stk->stack_a->next->next)
		{
			if (stk->stack_a->numb < stk->stack_a->next->numb)
				move_sa(stk->stack_a, stk);
			move_pb(&stk);
			break ;
		}
		else
		{
			parse_utils(stk, target);
			target = find_minor(stk, target);
		}
	}
}
