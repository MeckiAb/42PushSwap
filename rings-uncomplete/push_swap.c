/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:41:39 by labderra          #+#    #+#             */
/*   Updated: 2024/05/21 18:35:52 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ring	*load_stack(t_ring *stack, int *arr, int len)
{
	t_item	*aux;

	aux = (t_item *)malloc(sizeof(t_item));
	if (!aux)
		return (stack = clear_ring(stack), stack);
	while (len)
		stack = push(stack, aux);
	return (stack);
}

static int	chk_dup(int *arr, int len)
{
	int	i;

	while (len)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i++] == arr[len])
				return (1);
		}
		len--;
	}
	return (0);
}

t_ring	*chk_input(int argc, char **argv, t_ring *a_stack)
{
	int		i;
	int		*temp;

	if (argc < 2)
		return (NULL);
	temp = (int *)malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], ft_itoa(ft_atoi(argv[i])), ft_strlen(argv[i]))
			|| (ft_atoi(argv[i]) && argv[i][0] == '+'
			&& !ft_strncmp(&argv[i][1], ft_itoa(ft_atoi(argv[i])),
			ft_strlen(argv[i]) - 1)))
			temp[i - 1] = ft_atoi(argv[i]);
		else
			return (free(temp), NULL);
		i++;
	}
	if (!chk_dup(temp, argc - 1))
		a_stack = load_stack(a_stack, temp, argc - 1);
	return (free(temp), a_stack);
}

int	main(int argc, char **argv)
{
	int		lst_len;
	t_ring	*a_stack;
	t_ring	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	a_stack = chk_input(argc, argv, &a_stack);
	if (!a_stack)
		return (ft_printf("Error.\n"), 0);
	return (0);
}
