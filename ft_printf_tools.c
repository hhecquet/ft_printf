/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/17 11:42:56 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_flag(long nb, t_flags flags, char format)
{
	unsigned long	n;
	int				count;

	flags.format = format;
	count = ft_count_num(nb);
	if (format != 'u' && nb > 0 && flags.plus == 1)
		count += write(1, "+", 1);
	else if (format != 'u' && nb > 0 && flags.space == 1)
		count += write(1, " ", 1);
	count += ft_putflag_before(flags, count, count);
	if (format != 'u' && nb < 0)
	{
		nb = nb * -1;
		write (1, "-", 1);
	}
	n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
	count += ft_putflag_after(flags, count, count);
	return (count);
}

int	ft_putstr_flag(char *str, t_flags flags, char format)
{
	int	count;

	flags.format = format;
	count = ft_strlen(str);
	count = ft_putflag_before(flags, count, count);
	while (*str++)
	{
		write(1, str, 1);
	}
	count = ft_putflag_after(flags, count, count);
	return (count);
}

int	ft_putahex(char *str, t_flags flags, char format)
{
	char		*hex;
	int			count;

	flags.format = format;
	count = 0;
	if (format == 'p' || flags.hash == 1)
		count += write(1, "0x", 2);
	count += ft_count_hex(str);
	count = ft_putflag_before(flags, count, count);
	hex = "0123456789abcdef";
	if (format == 'X')
	{
		while (*hex++)
		{
			*hex = ft_tolower(*hex);
		}
	}
	while (*str++)
	{
		count += write(1, &hex[*str / 16], 1);
		count += write(1, &hex[*str % 16], 1);
	}
	count = ft_putflag_after(flags, count, count);
	return (count);
}

int	ft_putchar_flag(char c, t_flags flags, char format)
{
	int	count;

	flags.format = format;
	count = 1;
	count = ft_putflag_before(flags, count, count);
	if (format == '%')
		write(1, "%", 1);
	else
		write(1, &c, 1);
	count = ft_putflag_after(flags, count, count);
	return (count);
}

int	ft_count_num(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count + 1);
}
