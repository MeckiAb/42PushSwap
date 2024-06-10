/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:01:15 by labderra          #+#    #+#             */
/*   Updated: 2024/06/09 20:40:55 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
	a_stack = chk_input(argc, argv, a_stack);
	if (!a_stack)
		return (ft_printf("Error\n"), 0);
	if (chk_sorted(a_stack))
		return (0);
	sort(&a_stack, &b_stack);
	ft_lstclear(&a_stack, &free);
 	return (0);
}
