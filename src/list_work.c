/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:11:40 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/05 21:00:53 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps_list	*new_node(int numb)
{
	t_ps_list	*node;

	node = malloc(sizeof(t_ps_list));
	if (!node)
		return (NULL);
	node->numb = numb;
	node->next = NULL;
	return (node);
}

t_ps_list	*add_back_front(t_ps_list *node, int pstn, t_ps_list *lst)
{
	t_ps_list	*temp;

	temp = lst;
	if (!lst)
		return (node);
	if (pstn == NEXT)
	{
		while (temp && temp->next != NULL)
			temp = temp->next;
		node->next = NULL;
		temp->next = node;
		return (lst);
	}
	else 
		node->next = lst;
	return (node);
}
