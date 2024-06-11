/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:45:27 by labderra          #+#    #+#             */
/*   Updated: 2024/05/07 22:45:27 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	print_token(char const *s, va_list ap, int i)
{
	if (*s == '%')
		i = print_char('%', i);
	else if (*s == 'c')
		i = print_char(va_arg(ap, int), i);
	else if (*s == 's')
		i = print_str(va_arg(ap, char *), i);
	else if (*s == 'i' || *s == 'd')
		i = print_nbr(va_arg(ap, int), &i);
	else if (*s == 'u')
		i = print_unbr((unsigned int)va_arg(ap, unsigned int), &i);
	else if (*s == 'x' || *s == 'X')
		i = print_hex(va_arg(ap, unsigned int), &i, *s - 23);
	else if (*s == 'p')
	{
		write(1, "0x", 2);
		i = print_ptr(va_arg(ap, void *), &i, 'a') + 2;
	}
	else
		return (-1);
	return (i);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, s);
	while (i >= 0 && *s)
	{
		if (*s != '%')
		{
			write(1, s++, 1);
			i++;
		}
		else
		{
			i = print_token(++s, ap, i);
			s++;
		}
	}
	va_end(ap);
	return (i);
}
