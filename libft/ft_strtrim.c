/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:20:27 by labderra          #+#    #+#             */
/*   Updated: 2024/04/17 12:57:01 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, (int)s1[i]) != NULL)
		i++;
	while (j >= i && ft_strchr(set, (int)s1[j]) != NULL)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
