/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:54:48 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/14 20:50:29 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	verify_numbs(t_ps_list *stk)
{
	t_ps_list	*a;
	t_ps_list	*b;

	a = stk;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->numb == b->numb)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}

void	sort_four(t_stacks *stk, int minor)
{
	if (best_moves(stk->stack_a, minor) >= 0)
		while (stk->stack_a->numb != minor)
			move_rra(&stk->stack_a, stk);
	else
		while (stk->stack_a->numb != minor)
			move_rra(&stk->stack_a, stk);
	move_pb(&stk);
	solve_three(stk);
	move_pa(&stk);
}

int	is_sorted(t_stacks *stk)
{
	t_ps_list	*lst;

	lst = stk->stack_a;
	while (lst->next)
	{
		if (lst->numb > lst->next->numb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static int	validation_item(char *argv)
{
	int	j;

	j = 0;
	// if (!argv[j])
	// 	return (return_error(), 1);
	if (argv[j] == '+' || argv[j] == '-')
		j++;
	while (argv[j] == '0')
		j++;
	if (ft_strlen(&argv[j]) > 10)
		return (return_error(), 1);
	while (argv[j])
	{
		if (ft_isdigit(argv[j]) == 0)
			return (return_error(), 1);
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
