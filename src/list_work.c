/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:11:40 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/27 14:53:57 by tsantana         ###   ########.fr       */
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
	node->prev = NULL;
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
		node->prev = temp;
		temp->next = node;
		return (lst);
	}
	while (lst && lst->prev != NULL)
		lst = lst->prev;
	node->next = lst;
	node->prev = NULL;
	lst->prev = node;
	return (node);
}
