/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:26:40 by avolcy            #+#    #+#             */
/*   Updated: 2023/07/31 15:33:26 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_specifier(char index, va_list arg_p)
{
	int	count;

	count = 0;
	if (index == 'c')
		count = ft_print_char(va_arg(arg_p, int));
	else if (index == 'd' || index == 'i')
		count = ft_print_nbr(va_arg(arg_p, int));
	else if (index == 's')
		count = ft_print_string(va_arg(arg_p, char *));
	else if (index == 'u')
		count = ft_print_unsigned(va_arg(arg_p, unsigned int));
	else if (index == 'x' || index == 'X')
		count = ft_print_hexadec(va_arg(arg_p, unsigned int), index);
	else if (index == 'p')
		count = ft_print_ptr(va_arg(arg_p, unsigned long));
	else
		count = ft_print_char(index);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		returned_len;
	va_list	arg_p;

	count = 0;
	va_start(arg_p, format);
	while (*format)
	{
		if (*format == '%')
			returned_len = ft_type_specifier(*(++format), arg_p);
		else
			returned_len = ft_print_char(*(format));
		if (returned_len == -1)
			return (-1);
		count += returned_len;
		++format;
	}
	va_end(arg_p);
	return (count);
}
