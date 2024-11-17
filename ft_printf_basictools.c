/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basictools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:50:56 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/17 11:36:07 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		j++;
	}
	return (j);
}

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return (c + 32);
	}
	return (c);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

int	ft_count_hex(char *str)
{
	int		count;
	char	*hex;

	count = 1;
	hex = str;
	while (*hex++)
	{
		*hex = *hex / 16;
		*hex = *hex % 16;
		count += 2;
	}
	return (count);
}
