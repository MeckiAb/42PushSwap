/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:42:29 by labderra          #+#    #+#             */
/*   Updated: 2024/06/06 13:37:41 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	del_item(void *item)
{
	free(item);
}

static void	init_target_pos(int *arr, int *ordered, int len)
{
	int	i;
	int	j;

	i = 0;
	ordered[0] = 2147483647;
	while (i < len)
	{
		if (arr[i] < ordered[0])
			ordered[0] = arr[i];
		i++;
	}
	i = 1;
	while (i < len)
	{
		j = 0;
		ordered[i] = 2147483647;
		while (j < len)
		{
			if (arr[j] > ordered[i - 1] && arr[j] < ordered[i])
				ordered[i] = arr[j];
			j++;
		}
		i++;
	}
}
static int	set_target_pos(int *ordered, int value, int len)
{
	while (len--)
		if (ordered[len] == value)
			return (len);
	return (-1);
}

static t_list	*load_stack(t_list **stack, int *arr, int len)
{
	t_list	*new;
	t_item	*item;
	int		ordered[len];
	int		size;

	size = len;
	init_target_pos(arr, ordered, len);	
	while (len--)
	{
		item = (t_item *)malloc(sizeof(t_item));
		new = (t_list *)malloc(sizeof(t_list));
		if (!item || !new)
		{
			ft_lstclear(stack, &free);
			return (NULL);
		}
		item->value = arr[len];
		item->target = set_target_pos(ordered, item->value, size);
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
