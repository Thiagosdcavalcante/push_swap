/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:54:48 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/09 22:01:20 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sup_verify(t_stacks **stk)
{
	static int i = 0;

	if (!(*stk)->sup.end_b || !(*stk)->stack_b->next || !(*stk)->stack_b)
		return ;
	while ((*stk)->stack_a->numb >= (((*stk)->pivot + (*stk)->maxm) / 2) && (*stk)->stack_a->numb < (*stk)->sup.end_b->numb)
	{
		move_rrb(&(*stk)->stack_b, (*stk));
	}
	move_pb(stk);
	while (i > 0)
		rotate(2, &(*stk)->stack_b, (*stk));
}

void verify(t_stacks **stk)
{
	if ((*stk)->sup.end_b)
	{
		if ((*stk)->sup.end_b->numb < (*stk)->stack_b->numb)
			rotate(2, &(*stk)->stack_b, (*stk));
		if ((*stk)->stack_b->next)
		{
			if ((*stk)->stack_b->numb > (*stk)->stack_b->next->numb)
				move_sb((*stk)->stack_b, (*stk));
		}
	}
	// if ((*stk)->stack_b && (*stk)->sup.end_b)
	// {
	// 	while ((*stk)->stack_a->numb < (*stk)->sup.end_b->numb)
	// 	{
	// 		move_rrb(&(*stk)->stack_b, (*stk));
	// 		put_sup(stk);
	// 	}
	// }
}

void	divide_stack(t_stacks *stk)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		sup_verify(&stk);
		if (stk->stack_a->numb > stk->pivot)
		{
			move_pb(&stk);
			verify(&stk);
		}
		else
		{
			if (find_last_big(stk->stack_a, stk->pivot) > 0)
				while (stk->stack_a->numb <= stk->pivot)
					move_rra(&stk->stack_a, stk);
			else
				while (stk->stack_a->numb <= stk->pivot)
					rotate(1, &stk->stack_a, stk);
		}
		i = has_bigger(stk->stack_a, stk->pivot);
	}
}

static int	validation_item(char *argv)
{
	int	j;

	j = 0;
	if (argv[j] == '+' || argv[j] == '-')
		j++;
	while (argv[j] == '0')
		j++;
	while (argv[j])
	{
		if (ft_isdigit(argv[j]) == 0)
			return (return_error(2), 1);
		j++;
	}
	return (0);
}

int	validation_args(char *args[])
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (validation_item(args[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
