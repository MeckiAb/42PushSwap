/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:42:29 by labderra          #+#    #+#             */
/*   Updated: 2024/06/10 13:24:06 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*load_stack(t_list **stack, int *arr, int len)
{
	t_list	*new;
	t_item	*item;
	int		*ordered;
	int		size;

	ordered = (int *)malloc(sizeof(int) * len);
	if (!ordered)
		return (NULL);
	size = len;
	init_target_pos(arr, ordered, len);
	while (len--)
	{
		item = (t_item *)malloc(sizeof(t_item));
		new = (t_list *)malloc(sizeof(t_list));
		if (!item || !new)
			return (ft_lstclear(stack, &free), NULL);
		item->value = arr[len];
		item->target = set_target_pos(ordered, item->value, size);
		item->cost = 0;
		new->content = item;
		ft_lstadd_front(stack, new);
	}
	return (free(ordered), *stack);
}
