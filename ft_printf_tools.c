/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/15 11:24:53 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putnbr_flag(long nb, char *flag, int size_flag, int is_unsigned)
{
	unsigned long	n;

	if (is_unsigned == 0 && nb < 0)
	{
		nb = nb * -1;
		write (1, '-', 1);
	}
	n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

int	ft_putstr_flag(char *str, char *flag, int size_flag)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_putahex(char *str, char format, char *flag, int size_flag)
{
	const char		*hex;

	hex = "0123456789abcdef";
	if (format == 'X')
		ft_tolower(hex);
	while (*str++)
	{
		write(1, &hex[*str / 16], 1);
		write(1, &hex[*str % 16], 1);
	}
}

int	ft_putchar_flag(char c, int size_flag, char format)
{
	int	i;

	i = 0;
	while (size_flag > 1)
	{
		if (format == '%')
			write(1, "0", 1);
		else
			write(1, " ", 1);
		size_flag--;
		i++;
	}
	if (format == '%')
		write(1, '%', 1);
	else
		write(1, &c, 1);
	return (i + 1);
}