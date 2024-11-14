/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/14 15:59:42 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_flag(int nb, char *flag, int size_flag)
{
	long	n;//unsigned ?

	n = nb;
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	if (n >= 10)//if flag reagir differement
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}
void	ft_putstr_flag(char *str, char *flag, int size_flag)
{
		while (*str)
	{
		write(1, str, 1);
		str++;//if flag reagir differement
	}
}

void ft_putahex(char	*str, char format, char *flag, int size_flag)
{
	const char		*hex;

	hex = "0123456789abcdef";
	if (format == 'X')
			ft_tolower(hex); //libft
	while (*str++)
	{
		write(1, &hex[*str / 16], 1);
		write(1, &hex[*str % 16], 1);
	}
}
void	ft_putnbr_hex(unsigned long n)
{
	char	*base = "0123456789abcdef";

	if (n >= 16)
		ft_putnbr_hex(n / 16);
	write(1, &base[n % 16], 1);
}