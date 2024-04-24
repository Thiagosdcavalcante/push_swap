/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:54:48 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/24 14:58:36 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	equal_numbs(t_ps_list *lst)
{
	long int	target;
	t_ps_list	*head;
	t_ps_list	*check_lst;
	int			i;
	int			j;

	i = 0;
	head = lst;
	check_lst = lst;
	while (check_lst)
	{
		target = check_lst->numb;
		j = 0;
		head = lst;
		while (head)
		{
			if (head->numb == target && (i != j))
				return (1);
			head = head->next;
			j++;
		}
		check_lst = check_lst->next;
		i++;
	}
	return (0);
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
