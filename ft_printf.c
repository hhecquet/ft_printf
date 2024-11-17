/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:36:37 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/17 09:47:49 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags flags;
	int		count;
	
	count = 0;
	flags.size = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_parser_flag(*format, flags);
			if (*format == 'c' || *format == '%')
				count += ft_putchar_flag(va_arg(args, int), flags, *format);
			else if (*format == 's')
				count += ft_putstr_flag(va_arg(args, char *), flags, *format);
			else if (*format == 'i' || *format == 'd' || *format == 'u')
				count += ft_putnbr_flag(va_arg(args, long), flags, *format);
			else if (*format == 'x' || *format == 'X' || *format == 'p')
				count += ft_putahex(va_arg(args, void *), flags, *format);
		}
		else
			count += write(1, format++, 1);
	}
	return (count);
}
void	ft_parser_flag(char *format, t_flags flags)
{
	flags.minus = 0;
    flags.plus = 0;
    flags.zero = 0;
    flags.space = 0;
    flags.hash = 0;
	while (*format != 'c' || *format != 's' || *format != 'i' || *format != 'd' || *format != 'u' || *format != 'x' || *format != 'X' || *format != 'p')
    {
        if (*format == '-')
            flags.minus = 1;
        else if (*format == '+')
            flags.plus = 1;
        else if (*format == ' ')
            flags.space = 1;
        else if (*format == '#')
            flags.hash = 1;
        else if (*format >= '0' && *format <= '9')
        	while (*format >= '0' && *format <= '9')
			{
				if (*format == '0' && flags.size == 0)
					flags.zero = 1;
				else
					flags.size = (flags.size * 10) + (*format - '0');
			}
		format++;
    }
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