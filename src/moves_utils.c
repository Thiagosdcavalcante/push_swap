/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:17:23 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/14 16:48:35 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	best_moves(t_ps_list *lst, int pvt)
{
	t_ps_list	*srch;
	int			i;
	int			j;

	srch = lst;
	i = 0;
	j = 0;
	if (srch->numb < pvt)
		return (0);
	while (srch && srch->numb >= pvt)
	{
		i++;
		srch = srch->next;
	}
	srch = lst;
	while (srch)
	{
		if (srch->numb < pvt)
			j = 0;
		else
			j++;
		srch = srch->next;
	}
	return (i - (j + 1));
}

int	has_minor_target(t_ps_list *lst, int target)
{
	t_ps_list	*find;

	if (!lst || !lst->next)
		return (0);
	find = lst;
	while (find->next)
	{
		if (find->numb < target)
			return (1);
		find = find->next;
	}
	return (0);
}
