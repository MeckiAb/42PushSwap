/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:42:33 by labderra          #+#    #+#             */
/*   Updated: 2024/05/21 19:18:22 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv)
{
	int i = 0;

	ft_printf("Argumentos : %d\n", argc);
	while (i < argc)
	{
		ft_printf("%d - %s - %i - ", i, argv[i], ft_atoi(argv[i]));
		if (!ft_strncmp(argv[i], ft_itoa(ft_atoi(argv[i])), ft_strlen(argv[i]))
				|| (ft_atoi(argv[i]) && argv[i][0] == '+'
				&& !ft_strncmp(&argv[i][1], ft_itoa(ft_atoi(argv[i])),
				ft_strlen(argv[i]) - 1)))
			ft_printf("valid\n");
		else
			ft_printf("INVALID\n");
		i++;
	}
	return (0);
}
