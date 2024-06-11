/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:12:09 by labderra          #+#    #+#             */
/*   Updated: 2024/06/12 01:15:38 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chk_dup(int *arr, int len)
{
	int	i;

	while (len > 1)
	{
		i = 0;
		while (i < len - 1)
		{
			if (arr[i++] == arr[len - 1])
				return (1);
		}
		len--;
	}
	return (0);
}

int	chk_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (((t_item *)(stack->content))->value >
			((t_item *)(stack->next->content))->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_list	*chk_split_input(char *arg, t_list *a_stack)
{
	int		argc;
	char	**argv;
	char	*str;

	str = ft_strjoin("x ", arg);
	argv = ft_split(str, ' ');
	free(str);
	argc = 1;
	while (argv[argc])
		argc++;
	a_stack = chk_input(argc, argv, a_stack);
	while (argc--)
		free(argv[argc]);
	free (argv);
	return (a_stack);
}

t_list	*chk_input(int argc, char **argv, t_list *a_stack)
{
	int		i;
	int		*temp;
	char	*chk;

	temp = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], "", ft_strlen(argv[i])))
			return (free(temp), NULL);
		chk = ft_itoa(ft_atoi(argv[i]));
		if (!ft_strncmp(argv[i], chk, ft_strlen(argv[i])) || (ft_atoi(argv[i])
				&& argv[i][0] == '+' && !ft_strncmp(&argv[i][1], chk,
			ft_strlen(argv[i]) - 1)))
			temp[i - 1] = ft_atoi(argv[i]);
		else
			return (free(temp), free(chk), NULL);
		free(chk);
	}
	if (!chk_dup(temp, argc - 1))
		a_stack = load_stack(&a_stack, temp, argc - 1);
	return (free(temp), a_stack);
}
