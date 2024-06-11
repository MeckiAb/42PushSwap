/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:45:51 by labderra          #+#    #+#             */
/*   Updated: 2024/05/08 11:54:19 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_char(int c, int i)
{
	unsigned char	aux;

	aux = (unsigned char)c;
	write(1, &aux, 1);
	return (i + 1);
}
