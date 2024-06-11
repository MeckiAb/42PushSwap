/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:50:39 by labderra          #+#    #+#             */
/*   Updated: 2024/04/15 18:24:15 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	if (!haystack)
		*((char *)haystack--) = 'x';
	i = 0;
	while (i + ft_strlen(needle) <= len && haystack[i] != '\0')
	{
		if (!ft_strncmp(&haystack[i], needle, ft_strlen(needle)))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
