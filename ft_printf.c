/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:36:37 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/14 15:50:29 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*flag;
	int		size_flag;

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
				ft_putchar_fd(va_arg(args, char),1);
			else if (*format == 's')
				ft_putstr_fd(va_arg(args, char*),1);
			else if (*format == 'p')
				ft_putstr_flag(va_arg(args, void*), flag, size_flag); //putstr ? 🚨​ hexa
			else if (*format == 'i' || *format == 'd')
				ft_putnbr_flag(va_arg(args, int),flag);
			else if (*format == 'u')
				ft_putstr_flag(va_arg(args, unsigned int), flag, size_flag); //putnbr usigned
			else if (*format == 'x' || *format == 'X')
				ft_putstr_flag(va_arg(args, void*), flag, size_flag); //non printable pour ft_hexa 🚨
			else if (*format == '%')
				ft_putchar(va_arg(args, char));
		}
	}
}
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
printf("%-10s\n", "abc"); // Affiche "abc       " */