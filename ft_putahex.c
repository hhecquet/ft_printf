/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:25:04 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/18 14:48:37 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len += 1;
	while (n)
	{
		n /= base;
		len++;
	}
	if (len < 0)
		return (0);
	return (len);
}

void	ft_putahex(unsigned long long nb, int *len, char *base, t_flags *flags)
{
	while (flags->sizep > 0)
	{
		*len += ft_putchar('0');
		flags->sizep--;
	}
	if (nb >= 16)
		ft_putahex(nb / 16, len, base, flags);
	*len += ft_putchar(base[nb % 16]);
}

int	ft_putahash(unsigned long long n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.hash == 1 && n != 0)
	{
		if (flags.flag == 'X')
			count += ft_putstr("0X");
		else
			count += ft_putstr("0x");
	}
	if (flags.flag == 'p')
		count += ft_putstr("0x");
	return (count);
}

int	ft_print_hex(unsigned long long n, t_flags flags)
{
	char	*hex;
	int		count;
	int		iszero;

	count = 0;
	iszero = 0;
	if (flags.flag == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n == 0 && flags.point == 1 && flags.sizep == 0)
		iszero = 1;
	compareformatsizep(n, 0, iszero, &flags);
	if (iszero == 1)
		return (count += putformat(flags.format, flags));
	if (!flags.minus && flags.format)
		count += putformat(flags.format, flags);
	count += ft_putahash(n, flags);
	ft_putahex(n, &count, hex, &flags);
	if (flags.minus && flags.format)
		count += putformat(flags.format, flags);
	return (count);
}

int	ft_putstring(char *str, t_flags flags)
{
	int		len;
	int		count;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (len >= flags.sizep && flags.point)
		len = flags.sizep;
	if (flags.format > len && !flags.minus)
		count += putformat(flags.format - len, flags);
	count += ft_putstr_len(str, len);
	if (flags.format > len && flags.minus)
		count += putformat(flags.format - len, flags);
	return (count);
}