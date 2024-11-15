/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:36:37 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/15 09:46:49 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*flag;
	int		size_flag;
	int		count;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (format == '-')
			{
				*flag++ = '-';
				format++;
			}
			else if (format == '0')
			{
				*flag++ = '0';
				format++;
			}
			else if (format == '+')
			{
				*flag++ = '+';
				format++;
			}
			else if (format == ' ')
			{
				*flag++ = ' ';
				format++;
			}
			else if (format == '#')
			{
				*flag++ = '#';
				format++;
			}
			while(format >= '0' && format <= '9')
			{
				if (format == '0' && size_flag == 0)
					format++;
				else
					size_flag = size_flag * 10 + (format - '0');
			}//nickel jusque la 🐈​
			if (*format == 'c')
				count = ft_putchar(va_arg(args, char));
			else if (*format == 's')
				count = ft_putstr(va_arg(args, char*));
			else if (*format == 'p')
				count = ft_putstr_flag(va_arg(args, void*), flag, size_flag); //putstr ? 🚨​ hexa
			else if (*format == 'i' || *format == 'd')
				count = ft_putnbr_flag(va_arg(args, long), flag, 0);
			else if (*format == 'u')
				count = ft_putstr_flag(va_arg(args, long), flag, size_flag,1); //putnbr usigned
			else if (*format == 'x' || *format == 'X')
				count = ft_putahex(va_arg(args, void*), flag, size_flag); //non printable pour count = ft_hexa 🚨
			else if (*format == '%')
				count = ft_putchar(va_arg(args, char));
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
/* -0 #+ gerer avec une string et lanalyser
 // Vérifier la largeur
            if (*format >= '1' && *format <= '9') {
                width = *format - '0'; // Largeur simple (pour la démonstration)
                format++;
            }

+ et " " pour d et i
# pour x et X
-0+ #

printf("%#p\n", (void*)12345678);  // Affiche "0x12345678"
printf("%+d\n", 42);    // Affiche "+42"
printf("%+d\n", -42);   // Affiche "-42"
printf("% d\n", 42);    // Affiche " 42"
printf("% d\n", -42);   // Affiche "-42"
printf("%05d\n", 42);    // Affiche "00042"
printf("%08x\n", 255);   // Affiche "000000ff"
printf("%-5d\n", 42);    // Affiche "42   "
printf("%-10s\n", "abc"); // Affiche "abc       " 
printf("%05d", 2); // This will print "00002"
printf("%%");      // This will print "%"*/