/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:42:24 by avolcy            #+#    #+#             */
/*   Updated: 2023/07/31 16:26:53 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static	long	ft_count_digit(long num, int base)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}
*/
int	ft_print_nbr(int n)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	if (s == NULL)
		return (-1);
	len = ft_print_string(s);
	free(s);
	if (len == -1)
		return (-1);
	return (len);
}
