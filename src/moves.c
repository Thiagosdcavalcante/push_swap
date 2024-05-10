/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:12:17 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/09 18:41:26 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	has_bigger(t_ps_list *a, int pivot)
{
	t_ps_list	*lst;

	lst = a;
	while (lst->next)
	{
		if (lst->numb > pivot)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	find_last_big(t_ps_list *lst, int pvt)
{
	t_ps_list	*srch;
	int			i;
	int			j;

	srch = lst;
	i = 0;
	j = 0;
	if (srch->numb > pvt)
		return (0);
	while (srch && srch->numb <= pvt)
	{
		i++;
		srch = srch->next;
	}
	srch = lst;
	while (srch)
	{
		if(srch->numb > pvt)
			j = 0;
		j++;
		srch = srch->next;
	}
	#include <stdio.h>
	printf("%d %d\n", i, j);
	return (i - j);
}

int	find_distance(t_ps_list **to_find, int target)
{
	t_ps_list	*search;
	int	i;
	int j;

	i = 0;
	j = 0;
	search = (*to_find);
	while (search->numb != target)
	{
		i++;
		search = search->next;
	}
	while (search->next)
	{
		j++;
		search = search->next;
	}
	return (i - (j + 1));
}
