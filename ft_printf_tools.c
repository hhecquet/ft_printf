/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/17 09:45:13 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_flag(long nb, t_flags flags, char format)
{
	unsigned long	n;
	int				count;
	
	count = ft_count_num(nb);
	count +=; //parser flag
	if (format != 'u' && nb < 0)
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
	count +=; //parser flag
	return (count);
}

int	ft_putstr_flag(char *str, t_flags flags, char format)
{
	int	count;

	count = ft_strlen(str);
	count +=; //parser flag
	while (*str++)
	{
		write(1, str, 1);
	}
	count +=; //parser flag
	return (count);
}

int	ft_putahex(char *str, t_flags flags, char format)
{
	const char		*hex;
	int				count;
	
	count = 0;
	count +=; //parser flag
	hex = "0123456789abcdef";
	if (format == 'X')
		ft_tolower(hex);
	while (*str++)
	{
		count += write(1, &hex[*str / 16], 1);
		count += write(1, &hex[*str % 16], 1);
	}
	count +=; //parser flag
	return (count);
}

int	ft_putchar_flag(char c, t_flags flags, char format)
{
	int	count;

	count = 1;
	count +=; //parser flag
	if (format == '%')
		write(1, '%', 1);
	else
		write(1, &c, 1);
	count +=; //parser flag
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