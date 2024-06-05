/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:39:39 by labderra          #+#    #+#             */
/*   Updated: 2024/06/05 11:07:53 by labderra         ###   ########.fr       */
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
	int		steps;
	char	route;
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
void	del_item(void *item);
void	get_target_asc(t_list *i_stack, t_list *v_stack);
void	get_target_desc(t_list *i_stack, t_list *v_stack);
void	sort(t_list **a_stack, t_list **b_stack);
int		get_minimum(t_list *i_stack);
int		get_maximum(t_list *i_stack);
void	route(int value, t_list *v_stack, int target, t_list *t_stack);
int		chk_rotate_sorted_asc(t_list *stack);
int		chk_rotate_sorted_desc(t_list *stack);
int		chk_sorted(t_list *stack);
t_item	*next_item(t_list *stack);
void	move_item_ab(t_item *item, t_list **a_stack, t_list **b_stack);
void	move_item_ba(t_item *item, t_list **a_stack, t_list **b_stack);
void	print_stack(t_list *stack);

#endif