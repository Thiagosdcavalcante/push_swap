/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:47:15 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/25 15:32:54 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	return_error(int error)
{
	if (error == 1)
		ft_printf("Error\nFound Duplicated Numbers\n");
	else if (error == 2)
		ft_printf("Error\nSome Items Isn't a Number\n");
	else if (error == 3)
		ft_printf("Error\nSome Items Are Bigger Or Smaller Than a Interger\n");
	else if (error == 4)
		ft_printf("Error\nEmpty Argument\n");
	else if (error == 5)
		ft_printf("Error\nPush_swap Needs At Least 2 Numbers\n");
}
