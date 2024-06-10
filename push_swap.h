/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:39:39 by labderra          #+#    #+#             */
/*   Updated: 2024/06/10 12:46:50 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

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
void	sort(t_list **a_stack, t_list **b_stack);
int		chk_sorted(t_list *stack);
int		chk_rotate_sorted(t_list *a_stack);


#endif