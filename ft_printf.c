/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:36:37 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/18 09:49:48 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
    va_list	args;
    t_flags	flags;
    int		count;

    if (!format)
        return (-1);
    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            ft_init_flags(&flags);
            ft_parser_flag(&format, &flags);
            if (*format == 'c' || *format == '%')
                count += ft_putchar_flag(va_arg(args, int), flags, *format);
            else if (*format == 's')
                count += ft_putstr_flag(va_arg(args, char *), flags, *format);
            else if (*format == 'i' || *format == 'd' || *format == 'u')
                count += ft_putnbr_flag(va_arg(args, int), flags, *format);
            else if (*format == 'x' || *format == 'X')
                count += ft_putahex(va_arg(args, unsigned int), flags, *format);
            else if (*format == 'p')
                   count += ft_putahex(va_arg(args, unsigned long), flags, *format);
            format++;
        }
        else
            count += write(1, format++, 1);
    }
    va_end(args);
    return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

void    ft_parser_flag(const char **format, t_flags *flags)
{
    while (!ft_strchr("cspdiuxX%", **format) && **format != '\0')
    {
        if (**format == '-')
        {
            flags->minus = 1;
            flags->zero = 0;
        }
        else if (**format == '+')
            flags->plus = 1;
        else if (**format == '.')
        {
            flags->point = 1;
            (*format)++;
            flags->precision = 0;
            while (**format >= '0' && **format <= '9')
            {
                flags->precision = (flags->precision * 10) + (**format - '0');
                (*format)++;
            }
            (*format)--;
        }
        else if (**format == ' ')
            flags->space = 1;
        else if (**format == '#')
            flags->hash = 1;
        else if (**format >= '0' && **format <= '9')
        {
            if (**format == '0' && flags->size == 0)
                flags->zero = 1;
            else
                flags->size = (flags->size * 10) + (**format - '0');
        }
        (*format)++;
    }
}

void ft_init_flags(t_flags *flags)
{
    flags->size = 0;
    flags->format = 0;
    flags->minus = 0;
    flags->plus = 0;
    flags->zero = 0;
    flags->pourcent = 0;
    flags->space = 0;
    flags->hash = 0;
    flags->point = 0;
    flags->precision = 0;
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