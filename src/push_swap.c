/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:03:17 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/27 15:14:49 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_data(t_stacks *stack)
{
	t_ps_list	*lst_a;

	lst_a = stack->stack_a;
	stack->sup.head_a = lst_a;
	stack->minim = lst_a->numb;
	stack->maxm = lst_a->numb;
	while (lst_a)
	{
		if (lst_a->numb > stack->maxm)
			stack->maxm = lst_a->numb;
		if (lst_a->numb < stack->minim)
			stack->minim = lst_a->numb;
		lst_a = lst_a->next;
	}
	stack->pivot = ((stack->minim + stack->maxm) / 2);
	stack->sup.end_a = lst_a;
	lst_a = stack->stack_a;
	while (lst_a->numb != stack->maxm)
		lst_a = lst_a->next;
	stack->sup.end_b = lst_a;
}

static void	free_stacks(t_stacks stack)
{
	t_ps_list *temp;

	if (stack.stack_a)
		while (stack.stack_a)
		{
			temp = stack.stack_a;
			stack.stack_a = stack.stack_a->next;
			free(temp);
		}
	if (stack.stack_b)
		while (stack.stack_b)
		{
			temp = stack.stack_b;
			stack.stack_b = stack.stack_b->next;
			free(temp);
		}
}

static void	print_lst(t_ps_list *lst)
{
	while (lst)
	{
		ft_printf("%d  ", lst->numb);
		lst = lst->next;
	}
	write (1, "\n", 1);
}

static t_ps_list	*make_stack_a(char **arg)
{
	int			i;
	long int	numb;
	t_ps_list	*lst;

	i = 1;
	lst = NULL;
	while (arg[i])
	{
		numb = ft_atol(arg[i]);
		lst = add_back_front(new_node(numb), 1, lst);
		i++;
	}
	return (lst);
}

int main	(int argc, char *argv[])
{
	t_stacks	stacks;

	stacks = (t_stacks){0};
	stacks.stack_b = NULL;
	stacks.stack_a = NULL;
	if (argc < 3)
		return (return_error(5), 1);
	if (validation_args(argv) == 1)
		return (1);
	stacks.stack_a = make_stack_a(argv);
	init_data(&stacks);
	print_lst(stacks.stack_a);
	divide_stack(&stacks);
	print_lst(stacks.stack_b);
	free_stacks(stacks);
	return (0);	
}
