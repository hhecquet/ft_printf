/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:36:37 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/15 11:18:34 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*flag;
	int		size_flag;
	int		count;

	flag = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '-')
			{
				*flag++ = '-';
				format++;
			}
			else if (*format == '0')
			{
				*flag++ = '0';
				format++;
			}
			else if (*format == '+')
			{
				*flag++ = '+';
				format++;
			}
			else if (*format == ' ')
			{
				*flag++ = ' ';
				format++;
			}
			else if (*format == '#')
			{
				*flag++ = '#';
				format++;
			}
			while (*format >= '0' && *format <= '9')
			{
				if (*format == '0' && size_flag == 0)
					format++;
				else
					size_flag = (size_flag * 10) + (*format - '0');
			}
			if (*format == 'c' || *format == '%')
				count += ft_putchar_flag(va_arg(args, int), size_flag, *format);
			else if (*format == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (*format == 'i' || *format == 'd')
				count += ft_putnbr_flag(va_arg(args, long), flag, size_flag, 0);
			else if (*format == 'u')
				count += ft_putnbr_flag(va_arg(args, long), flag, size_flag, 1);
			else if (*format == 'x' || *format == 'X' || *format == 'p')
				count += ft_putahex(va_arg(args, void *), *format,
						flag, size_flag);
		}
		else
		{
			count += 1;
			write(1, *format, 1);
			format++;
		}
	}
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

/* printf("%#p\n", (void*)12345678);  // Affiche "0x12345678"
printf("%+d\n", 42);    // Affiche "+42"
printf("%+d\n", -42);   // Affiche "-42"
printf("% d\n", 42);    // Affiche " 42"
printf("% d\n", -42);   // Affiche "-42"
printf("%05d\n", 42);    // Affiche "00042"
printf("%08x\n", 255);   // Affiche "000000ff"
printf("%-5d\n", 42);    // Affiche "42   "
printf("%-10s\n", "abc"); // Affiche "abc       " 
printf("%05d", 2); // This will print "00002"
printf("%%");      // This will print "%" */