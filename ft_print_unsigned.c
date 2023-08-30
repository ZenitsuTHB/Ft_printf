/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:02:48 by avolcy            #+#    #+#             */
/*   Updated: 2023/07/31 15:32:30 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	unsigned	int	ft_count_digit(unsigned int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char				*arr;
	int					count;
	unsigned int		d;
	long int			nb;

	nb = n;
	count = ft_count_digit(nb);
	arr = (char *)malloc(sizeof(char) * (count + 1));
	if (!arr)
		return (NULL);
	arr[count] = '\0';
	while (count--)
	{
		d = nb / 10;
		arr[count] = 48 + nb % 10;
		nb = d;
	}
	return (arr);
}

int	ft_print_unsigned(unsigned int num)
{
	int		count;
	char	*str;

	str = ft_uitoa(num);
	if (str == NULL)
		return (-1);
	count = ft_print_string(str);
	free(str);
	if (count == -1)
		return (-1);
	return (count);
}
