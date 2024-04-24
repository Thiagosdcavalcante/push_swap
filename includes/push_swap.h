/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:05:56 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/24 14:52:05 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"

typedef struct s_ps_list
{
	long int			numb;
	struct s_ps_list	*next;
	struct s_ps_list	*prev;
}	t_ps_list;

typedef struct s_support
{
	t_ps_list	*head_a;
	t_ps_list	*end_a;
	t_ps_list	*head_b;
	t_ps_list	*end_b;
}	t_sup;

typedef struct s_stacks
{
	long int	pivot;
	t_sup		sup;
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;
}	t_stacks;


enum e_position
{
	NEXT = 1,
	PREV = 2
};

int		check_args(char *arg);
int		validation_args(char *args[]);
int		ft_atol(const char *nptr);
void	move_pa(t_stacks *stack);
void	move_pb(t_stacks *stack);
void	move_sa(t_stacks *stack);
void	move_sb(t_stacks *stack);
void	move_ss(t_stacks *stack);
void	move_rb(t_stacks *stack);
void	move_ra(t_stacks *stack);
void	move_rr(t_stacks *stack);
void	move_rra(t_stacks *stack);
void	move_rrb(t_stacks *stack);
void	move_rrr(t_stacks *stack);
void	return_error(int error);
t_ps_list	*new_node(int numb);
t_ps_list	*add_back_front(t_ps_list *node, int pstn, t_ps_list *lst);

#endif
