/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:01:03 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/09 18:51:12 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_all_below_in_b(int pvt, t_ps_list *lst)
{
	t_ps_list *tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->numb <= pvt)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	init_b_again(t_stacks **stk)
{
	t_ps_list	*tmp;
	t_ps_list	*tmp2;

	tmp = (*stk)->stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	(*stk)->stack_b = tmp2;
	(*stk)->stack_b->next = NULL;
	tmp->next = NULL;
	write (1, "rra\n", 4);
	write (1, "pb\n", 3);
}

void	minor_to_b(t_stacks *stk)
{
	int	i;

	init_b_again(&stk);
	i = 1;
	if (!stk->stack_a || !stk->stack_b)
		return ;
	while ((stk->stack_a && stk->stack_b) && i != 0)
	{
		if (stk->stack_a->numb > stk->pivot)
			rotate(1, &stk->stack_a, stk);
		else
			move_pb(&stk);
		i = is_all_below_in_b((int)stk->pivot, stk->stack_a);
	}
}

