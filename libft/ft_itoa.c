/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:42:15 by labderra          #+#    #+#             */
/*   Updated: 2024/04/16 10:39:54 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	str[15];
	int		i;
	int		sign;

	sign = 0;
	i = 14;
	str[i--] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	else if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (sign == -1)
		str[i--] = '-';
	return (ft_strdup(&str[i + 1]));
}
