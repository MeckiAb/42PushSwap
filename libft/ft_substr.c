/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:29:03 by labderra          #+#    #+#             */
/*   Updated: 2024/04/12 17:57:22 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	size;

	if (start >= ft_strlen(s))
		size = 0;
	else if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start;
	else
		size = len;
	p = (char *)ft_calloc(sizeof(char), (size + 1));
	if (!p)
		return (NULL);
	ft_memmove(p, &s[start], size);
	return (p);
}
