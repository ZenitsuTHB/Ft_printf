/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:33:35 by avolcy            #+#    #+#             */
/*   Updated: 2023/07/31 16:53:05 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long num)
{
	int	len;

	len = 0;
	if (num > 15)
		ft_printhex(num / 16);
	len = write(1, &"0123456789abcdef"[num % 16], sizeof (char));
	if (len == -1)
		return (-1);
	return (len);
}

int	cont_numbers(unsigned long num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

int	ft_print_ptr(unsigned long num)
{
	int	len;

	len = 2;
	if (num == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += cont_numbers(num);
	if (ft_printhex(num) == -1)
		return (-1);
	if (len == 1)
		return (-1);
	return (len);
}
/*
 int main()
{
	int a = 8;
	int my;
	int pf;
	my = ft_printf("%p", &a);
	printf("\n");
	pf = printf("%p", &a);

	printf("\nmi funcion = %d, funcion de pf = %d\n", my, pf);
}
*/
