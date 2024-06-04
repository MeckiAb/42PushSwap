/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:42:29 by labderra          #+#    #+#             */
/*   Updated: 2024/06/04 11:35:04 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	del_item(void *item)
{
	free(item);
}

static t_list	*load_stack(t_list **stack, int *arr, int len)
{
	t_list	*new;
	t_item	*item;

	while (len-- > 0)
	{
		item = (t_item *)malloc(sizeof(t_item));
		new = (t_list *)malloc(sizeof(t_list));
		if (!item || !new)
		{
			ft_lstclear(stack, &del_item);
			return (NULL);
		}
		item->value = arr[len];
		item->target = 0;
		item->steps = 0;
		item->route = '0';
		new->content = item;
		ft_lstadd_front(stack, new);

	}
	return (*stack);
}

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

t_list	*chk_input(int argc, char **argv, t_list *a_stack)
{
	int		i;
	int		*temp;

	if (argc == 2)
	{
		argv = ft_split(ft_strjoin("x ", argv[1]), ' ');
		argc = 1;
		while (argv[argc])
			argc++;
	}
	temp = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], ft_itoa(ft_atoi(argv[i])), ft_strlen(argv[i]))
			|| (ft_atoi(argv[i]) && argv[i][0] == '+'
			&& !ft_strncmp(&argv[i][1], ft_itoa(ft_atoi(argv[i])),
			ft_strlen(argv[i]) - 1)))
			temp[i - 1] = ft_atoi(argv[i]);
		else
			return (free(temp), NULL);
	}
	if (!chk_dup(temp, argc - 1))
		a_stack = load_stack(&a_stack, temp, argc - 1);
	return (free(temp), a_stack);
}
