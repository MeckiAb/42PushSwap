/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:17:42 by labderra          #+#    #+#             */
/*   Updated: 2024/04/15 17:36:03 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	i;
	int		j;

	list = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!list)
		return (NULL);
	j = 0;
	while (words(s, c))
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (*s && *s != c && s++)
			i++;
		list[j] = ft_substr(s - i, 0, i);
		if (!list[j])
		{
			while (j--)
				free(list[j]);
			return (free(list), NULL);
		}
		j++;
	}
	return (list[j] = NULL, list);
}
