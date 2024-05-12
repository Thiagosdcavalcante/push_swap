/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:26:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/12 05:07:51 by tsantana         ###   ########.fr       */
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
	if (size <= 10)
		parse_5(stk);
	else
	    random_parse(stk);
}

static int	find_target(t_ps_list *lst)
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

static int	moves_end(t_ps_list *lst, int value)
{
	t_ps_list	*find;
	int			i;
	int			j;

	i = 0;
	j = 0;
	find = lst;
	while (find->next && find->numb != value)
	{
		i++;
		find = find->next;
	}
	while (find->next)
	{
		j++;
		find = find->next;
	}
	return (i - j);
}

// void	b_back_to_a(t_stacks *stk)
// {
// 	int	value;
//
// 	while (stk->stack_b)
// 	{
// 		else if (stk->stack_b->next && (value == stk->stack_b->next->numb))
// 		{
// 			if (stk->stack_a->numb > stk->stack_a->next->numb)
// 				move_ss(stk);
// 			else
// 		     	move_sb(stk->stack_b, stk);
// 		}
// 		else if (best_moves(stk->stack_b, value) > 0)
// 			move_rrb(&stk->stack_b, stk);
// 		else
// 			rotate(2, &stk->stack_b, stk);
// 	}
// 	stk->stack_b = NULL;
// }

void	end_sort(t_stacks *stk)
{
	int	target;

	while (stk->stack_b)
	{
		target = find_target(stk->stack_a);
		if (stk->stack_b->numb == target)
			move_pa(&stk);
		else if (stk->stack_b->next)
		{
			if (moves_end(stk->stack_b, target) >= 0)
				move_rrb(&stk->stack_b, stk);
			else if (moves_end(stk->stack_b, target) < 0)
			    rotate(2, &stk->stack_b, stk);
		}
	}
	stk->stack_b = NULL;
}
