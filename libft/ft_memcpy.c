/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:49:21 by labderra          #+#    #+#             */
/*   Updated: 2024/04/10 10:48:18 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr;

	if (!dst && !src)
		return (NULL);
	ptr = (char *)dst;
	while (n-- > 0)
		ptr[n] = ((char *)src)[n];
	return (dst);
}
