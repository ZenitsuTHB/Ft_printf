/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:56:17 by avolcy            #+#    #+#             */
/*   Updated: 2023/07/25 18:21:44 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_print_string(char *str)
{
	int	count;

	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	count = ft_strlen(str);
	if (write(1, str, count) == -1)
		return (-1);
	return (count);
}
/*int main ()
{
	ft_print_string("hola que tal test\n");
	ft_print_string("");
}*/
