/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:03:17 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/24 14:58:39 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		ft_printf("%d\n", lst->numb);
		lst = lst->next;
	}
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

	stacks = (t_stacks){NULL};
	if (argc < 3)
		return (return_error(5), 1);
	if (validation_args(argv) == 1)
		return (1);
	stacks.stack_a = make_stack_a(argv);
	print_lst(stacks.stack_a);
	free_stacks(stacks);
	return (0);	
}
