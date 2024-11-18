/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/18 14:51:38 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t  ft_strlen(const char *s)
{
	size_t  i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	checkspace(t_flags flags)
{
	if (flags.space)
		return (ft_putchar(' '));
	return (0);
}

void	compareformatsizep(long long n, int sign, int zero, t_flags *flags)
{
	int	base;
	int	len;

	if (flags->flag == 'x' || flags->flag == 'X' || flags->flag == 'p')
		base = 16;
	else
		base = 10;
	if (flags->flag == 'p')
		len = ft_ptrlen(n, base);
	else
		len = ft_intlen(n, sign, base, zero);
	if (flags->sizep > 0 && flags->sizep + sign >= len)
		flags->sizep = flags->sizep + sign - len;
	else
		flags->sizep = 0;
	if (flags ->format <= flags->sizep + len)
		flags->format = 0;
	if (flags->format > 0 && flags->format > flags->sizep + len)
		flags->format = flags->format - (flags->sizep + len);
	if (flags->format && sign && flags->zero)
	{
		flags->sizep += flags->format;
		flags->format = 0;
	}
}

int	ft_intlen(long long n, int sign, int base, int zero)
{
	int	len;

	len = 0;
	if (sign > 0 && !zero)
		len = 1;
	if (n == 0 && !zero)
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

int	parsesizep(const char *str, int i, t_flags *flags)
{
	flags->point = 1;
	flags->zero = 0;
	while (ft_isdigit(str[i]))
	{
		flags->sizep = (flags->sizep * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}