/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:39:56 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/08 16:15:32 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	put_sup_a(t_ps_list *lst, t_sup sup)
{
	t_ps_list	*a;

	if (!lst)
	{
		sup.end_a = NULL;
		sup.head_a = NULL;
	}
	else if (lst && !lst->next)
	{
		sup.end_a = lst;
		sup.head_a = lst;
	}
	else
	{
		a = lst;
		while (a->next)
		{
			if (a->numb > sup.end_a->numb)
				sup.end_a = a;
			a = a->next;
		}
	}
	sup.head_a = lst;
}

static void	put_sup_b(t_ps_list *lst, t_sup sup)
{
	t_ps_list	*b;

	b = lst;
	if (lst && !lst->next)
	{
		sup.end_b = lst;
		sup.head_b = lst;
	}
	else
	{
		if (sup.end_b == NULL)
			sup.end_b = lst;
		while (b->next)
		{
			if (b->numb > sup.end_b->numb)
				sup.end_b = b;
			b = b->next;
		}
	}
}

void	put_sup(t_stacks **stks)
{
	put_sup_a((*stks)->stack_a, (*stks)->sup);
	if ((*stks)->stack_b)
		put_sup_b((*stks)->stack_b, (*stks)->sup);
	else
	{
		(*stks)->sup.end_b = NULL;
		(*stks)->sup.head_b = NULL;
	}
}

