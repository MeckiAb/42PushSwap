/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:49:01 by labderra          #+#    #+#             */
/*   Updated: 2024/04/11 13:10:51 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	if (dstsize == 0 || ft_strlen(dst) > dstsize)
		return (dstsize + ft_strlen(src));
	return (ft_strlen(dst)
		+ ft_strlcpy(&dst[ft_strlen(dst)], src, dstsize - ft_strlen(dst)));
}
