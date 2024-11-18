/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:36:37 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/18 14:51:28 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.flag == '%')
		count += ft_putchar('%');
	else if (flags.flag == 'c')
		count += ft_putchar_c(va_arg(args, int), flags);
	else if (flags.flag == 's')
		count += ft_putstring(va_arg(args, char *), flags);
	else if (flags.flag == 'x' || flags.flag == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), flags);
	else if (flags.flag == 'p')
		count += ft_print_hex(va_arg(args, unsigned long long), flags);
	else if (flags.flag == 'd' || flags.flag == 'i')
		count += ft_putnbr(va_arg(args, int), flags);
	else if (flags.flag == 'u')
		count += ft_putnbr(va_arg(args, unsigned int), flags);
	else
		return (0);
	return (count);
}

int	parseformat(const char *str, int i, t_flags *flags)
{
	while (ft_isdigit(str[i]))
	{
		flags->format = (flags->format * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int	parserflag(const char *str, int i, t_flags *flags)
{
	while (str[i++])
	{
		if (!ft_isdigit(str[i]) && !ft_strchr("-. +#c%sxXuipd", str[i]))
			break ;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == '-')
			flags->minus = 1;
		if (str[i] == '0' && flags->minus == 0 && flags->point == 0)
			flags->zero = 1;
		if (ft_isdigit(str[i]) && !flags->point)
			i = parseformat(str, i, flags);
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '.')
			i = parsesizep(str, i + 1, flags);
		if (ft_strchr("csx%Xuipd", str[i]))
		{
			flags->flag = str[i];
			break ;
		}
	}
	return (i);
}

t_flags ft_init_flags(void)
{
	t_flags flags;
	
    flags.sizep = 0; //= prec
    flags.format = 0; //= width
    flags.minus = 0;
    flags.plus = 0;
    flags.zero = 0;
    flags.pourcent = 0;
    flags.space = 0;
    flags.hash = 0;
    flags.point = 0;
    flags.precision = 0;
	return (flags);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	flags = ft_init_flags();
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = parserflag(format, i, &flags);
			count += ft_print_format(args, flags);
			flags = ft_init_flags();
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}




/*
⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢻⣿⡗⢶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣄
⠀⢻⣇⠀⠈⠙⠳⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⠶⠛⠋⣹⣿⡿
⠀⠀⠹⣆⠀⠀⠀⠀⠙⢷⣄⣀⣀⣀⣤⣤⣤⣄⣀⣴⠞⠋⠉⠀⠀⠀⢀⣿⡟⠁
⠀⠀⠀⠙⢷⡀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀
⠀⠀⠀⠀⠈⠻⡶⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣠⡾⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⠃⠀⢠⠒⣆⠀⠀⠀⠀⠀⠀⢠⢲⣄⠀⠀⠀⢻⣆⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢰⡏⠀⠀⠈⠛⠋⠀⢀⣀⡀⠀⠀⠘⠛⠃⠀⠀⠀⠈⣿⡀⠀⠀⠀⠀
⠀⠀⠀⠀⣾⡟⠛⢳⠀⠀⠀⠀⠀⣉⣀⠀⠀⠀⠀⣰⢛⠙⣶⠀⢹⣇⠀⠀⠀⠀
⠀⠀⠀⠀⢿⡗⠛⠋⠀⠀⠀⠀⣾⠋⠀⢱⠀⠀⠀⠘⠲⠗⠋⠀⠈⣿⠀⠀⠀⠀
⠀⠀⠀⠀⠘⢷⡀⠀⠀⠀⠀⠀⠈⠓⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀
*/