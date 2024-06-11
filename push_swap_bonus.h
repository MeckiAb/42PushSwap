/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:39:39 by labderra          #+#    #+#             */
/*   Updated: 2024/06/11 12:42:41 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_item
{
	int		value;
	int		target;
	int		cost;
}	t_item;

void	pa(t_list **a_stack, t_list **b_stack);
void	pb(t_list **a_stack, t_list **b_stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **a_stack, t_list **b_stack);
void	rra(t_list **a_stack);
void	rrb(t_list **b_stack);
void	rrr(t_list **a_stack, t_list **b_stack);
void	sa(t_list *a_stack);
void	sb(t_list *b_stack);
void	ss(t_list *a_stack, t_list *b_stack);
t_list	*chk_input(int argc, char **argv, t_list *a_stack);
t_list	*chk_split_input(char *arg, t_list *a_stack);
int		chk_sorted(t_list *stack);
t_list	*load_stack(t_list **stack, int *arr, int len);

#endif