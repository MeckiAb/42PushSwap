/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintflib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:42:15 by labderra          #+#    #+#             */
/*   Updated: 2024/05/07 22:42:15 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	print_char(int c, int i);
int	print_str(char *s, int i);
int	print_nbr(int n, int *i);
int	print_unbr(unsigned int n, int *i);
int	print_hex(unsigned int n, int *i, char h);
int	print_ptr(void *n, int *i, char h);
int	ft_printf(char const *s, ...);

#endif