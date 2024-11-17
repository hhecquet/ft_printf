/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/17 17:24:41 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr_flag(long nb, t_flags flags, char format)
{
    unsigned long   n;
    int            count;
    int            len;

    count = 0;
    if (format == 'u')
        n = (unsigned int)nb;
    else if (nb < 0)
    {
        count = write(1, "-", 1);
        n = -nb;
    }
    else
    {
        handle_sign(nb, flags, &count, format);
        n = nb;
    }
    len = ft_count_num(n);
    if (flags.point)
    {
        if (flags.precision == 0 && n == 0)
            return (count);
        while (len < flags.precision)
        {
            write(1, "0", 1);
            count++;
            len++;
        }
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
    count += len;
    return (count);
}


int ft_putstr_flag(char *str, t_flags flags, char format)
{
    int     count;
    int     len;
    char    *null_str;

    null_str = "(null)";
    if (!str)
        str = null_str;
    flags.format = format;
    len = ft_strlen(str);
    if (flags.point)
    {
        if (flags.precision < len)
            len = flags.precision;
        if (flags.precision == 0)
            len = 0;
    }
    count = len;
    count = ft_putflag_before(flags, count, len);
    write(1, str, len);
    count = ft_putflag_after(flags, count, len);
    return (count);
}

static void write_hex_prefix(char format, t_flags flags, unsigned long n, int *count)
{
    if (format == 'p')
    {
        *count += write(1, "0x", 2);
        return;
    }
    if (flags.hash && n != 0)
    {
        if (format == 'X')
            *count += write(1, "0X", 2);
        else
            *count += write(1, "0x", 2);
    }
}

int ft_putahex(unsigned long n, t_flags flags, char format)
{
    int     count;
    char    buffer[17];
    int     i;
    int     pad_len;

    count = 0;
    i = 0;
    if (n == 0 && format == 'p')
    {
        write(1, "(nil)", 5);
        return (5);
    }
    write_hex_prefix(format, flags, n, &count);
    if (flags.point)
    {
        pad_len = flags.precision;
        fill_hex_buffer(n, buffer, &i, get_hex_base(format));
        while (i < pad_len)
            buffer[i++] = '0';
        if (!(flags.precision == 0 && n == 0))
            count += write(1, buffer, i);
    }
    else
    {
        fill_hex_buffer(n, buffer, &i, get_hex_base(format));
        count += write(1, buffer, i);
    }
    return (count);
}

int	ft_putchar_flag(char c, t_flags flags, char format)
{
	int	count;

	flags.format = format;
	count = 1;
	count = ft_putflag_before(flags, count, count);
	if (format == '%')
		write(1, "%", 1);
	else
		write(1, &c, 1);
	count = ft_putflag_after(flags, count, count);
	return (count);
}
