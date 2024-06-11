/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:45:44 by labderra          #+#    #+#             */
/*   Updated: 2024/05/08 11:59:10 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_hex(unsigned int n, int *i, char h)
{
	char	c;

	if (n > 15)
	{
		*i = print_hex(n / 16, i, h) + 1;
		n = n % 16;
		if (n < 10)
			c = n + '0';
		else
			c = n + h - 10;
		write(1, &c, 1);
	}
	else
	{
		n = n % 16;
		if (n < 10)
			c = n + '0';
		else
			c = n + h - 10;
		write(1, &c, 1);
		(*i)++;
	}
	return (*i);
}
