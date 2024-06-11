/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:48:20 by labderra          #+#    #+#             */
/*   Updated: 2024/05/08 11:56:07 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_str(char *s, int i)
{
	int	cnt;

	if (!s)
	{
		write(1, "(null)", 6);
		return (i + 6);
	}
	cnt = 0;
	while (s[cnt])
	{
		write(1, &s[cnt++], 1);
		i++;
	}
	return (i);
}
