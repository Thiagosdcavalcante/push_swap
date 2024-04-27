/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:54:48 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/27 14:54:30 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	divide_stack(t_stacks *stk)
{
	t_ps_list *lst;
	t_ps_list *temp;

	lst = stk->stack_a;
	while (lst)
	{
		if (lst->numb > stk->pivot)
		{
		   	ft_printf("PIVOT: %d NUMB: %d\n", stk->pivot, lst->numb);
			if (lst->next != NULL)
			   	lst = lst->next;
			temp = lst->prev;
		   	move_pb(temp, stk);
		}
		else
			lst = lst->next;
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
