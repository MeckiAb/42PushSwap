/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:01:15 by labderra          #+#    #+#             */
/*   Updated: 2024/06/12 01:20:52 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <unistd.h>

int	move_stack(t_list **a_stack, t_list **b_stack, char **move)
{
	if (ft_strncmp(*move, "pa\n", 3) == 0)
		pa(a_stack, b_stack);
	else if (ft_strncmp(*move, "pb\n", 3) == 0)
		pb(a_stack, b_stack);
	else if (ft_strncmp(*move, "sa\n", 3) == 0)
		sa(*a_stack);
	else if (ft_strncmp(*move, "sb\n", 3) == 0)
		sb(*b_stack);
	else if (ft_strncmp(*move, "ra\n", 3) == 0)
		ra(a_stack);
	else if (ft_strncmp(*move, "rb\n", 3) == 0)
		rb(b_stack);
	else if (ft_strncmp(*move, "rr\n", 3) == 0)
		rr(a_stack, b_stack);
	else if (ft_strncmp(*move, "rra\n", 4) == 0)
		rra(a_stack);
	else if (ft_strncmp(*move, "rrb\n", 4) == 0)
		rrb(b_stack);
	else if (ft_strncmp(*move, "rrr\n", 4) == 0)
		rrr(a_stack, b_stack);
	else
		return (0);
	return (1);
}

int	read_moves(t_list **a_stack, t_list **b_stack)
{
	char	*move;

	while (1)
	{
		move = get_next_line(0);
		if (!move)
			return (1);
		if (!move_stack(a_stack, b_stack, &move))
		{
			while (move)
			{
				free(move);
				move = get_next_line(0);
			}
			write(2, "Error\n", 6);
			return (0);
		}
		free(move);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		a_stack = chk_split_input(argv[1], a_stack);
	else
		a_stack = chk_input(argc, argv, a_stack);
	if (!a_stack)
		return (write(2, "Error\n", 6), 0);
	if (read_moves(&a_stack, &b_stack))
	{
		if (chk_sorted(a_stack) && !b_stack)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_lstclear(&a_stack, &free);
	ft_lstclear(&b_stack, &free);
	return (0);
}
