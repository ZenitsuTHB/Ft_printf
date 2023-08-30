/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:48:39 by avolcy            #+#    #+#             */
/*   Updated: 2023/07/24 15:36:25 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_hexadec(unsigned long n, char index)
{
	int		base;
	char	*str;
	char	*str1;
	int		err;

	str = "0123456789abcdef";
	str1 = "0123456789ABCDEF";
	base = 16;
	if (n / base)
	{
		err = ft_print_hexadec(n / base, index);
		if (err == -1)
			return (-1);
		err = ft_print_hexadec(n % base, index);
	}
	else
	{
		if (index == 'x')
			err = ft_print_char(str[n % base]);
		if (index == 'X')
			err = ft_print_char(str1[n % base]);
	}
	if (err == -1)
		return (-1);
	return (ft_count_digit(n, base));
}
