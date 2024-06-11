/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:43:26 by labderra          #+#    #+#             */
/*   Updated: 2024/04/09 12:13:00 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_strlen(const char *s)
{
	unsigned long int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
