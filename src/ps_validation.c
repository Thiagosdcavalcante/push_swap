/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:54:48 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/08 16:35:31 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void verify(t_stacks **stk)
{
	if ((*stk)->stack_b && (*stk)->sup.end_b)
	{
		while ((*stk)->stack_a->numb < (*stk)->sup.end_b->numb)
		{
			move_rrb(&(*stk)->stack_b, (*stk));
			put_sup(stk);
		}
	}
}

void	divide_stack(t_stacks *stk)
{
	t_ps_list *lst;

	lst = stk->sup.end_a;
	while (lst->numb != stk->stack_a->numb)
	{
		if (stk->stack_a->numb > stk->pivot)
		{
			verify(&stk);
			move_pb(&stk);
			// if (!stk->stack_b->next)
			// 	stk->sup.end_b = stk->stack_b;
			put_sup(&stk);
			if (stk->stack_b->next)
				ps_mvs_conditions(&stk);
		}
		else
			rotate(1, &stk->stack_a, stk);
	}
	if (stk->stack_a->numb > stk->pivot)
		move_pb(&stk);
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
