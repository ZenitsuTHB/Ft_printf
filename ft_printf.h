/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:10:56 by avolcy            #+#    #+#             */
/*   Updated: 2023/07/31 15:34:14 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int			ft_print_char(char c);
int			ft_print_string(char *string);
int			ft_print_ptr(unsigned long num);
int			ft_printf(const char *form, ...);
int			ft_print_unsigned(unsigned int num);
int			ft_print_nbr(int n);
int			ft_print_hexadec(unsigned long n, char index);
char		*ft_itoa(int n);
#endif
