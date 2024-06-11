/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:51:36 by labderra          #+#    #+#             */
/*   Updated: 2024/05/08 11:59:28 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_ptr(void *n, int *i, char h)
{
	char				c;
	unsigned long int	l;

	l = (unsigned long int)n;
	if (l > 15)
	{
		*i = print_ptr((void *)(l / 16), i, h) + 1;
		l = l % 16;
		if (l < 10)
			c = l + '0';
		else
			c = l + h - 10;
		write(1, &c, 1);
	}
	else
	{
		l = l % 16;
		if (l < 10)
			c = l + '0';
		else
			c = l + h - 10;
		write(1, &c, 1);
		(*i)++;
	}
	return (*i);
}
