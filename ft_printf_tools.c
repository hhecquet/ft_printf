/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/15 08:52:24 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putnbr_flag(long nb, char *flag, int size_flag, int is_unsigned)
{
	unsigned long	n;//unsigned ?

	if (is_unsigned == 0 && nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	n = nb;
	if (n >= 10)//if flag reagir differement
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
		str++;//if flag reagir differement
	}
}

int ft_putahex(char *str, char format, char *flag, int size_flag)
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
//count
//ft_flag