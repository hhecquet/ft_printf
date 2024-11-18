/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/18 10:56:11 by hhecquet         ###   ########.fr       */
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
        n = -nb;
        if (!flags.zero || flags.point)
            count = write(1, "-", 1);
    }
    else
    {
        handle_sign(nb, flags, &count, format);
        n = nb;
    }
    len = ft_count_num(n);
    if (flags.point && flags.precision == 0 && n == 0)
        return (count);
    if (nb < 0 && flags.zero && !flags.point)
        count = write(1, "-", 1);
    count = ft_putflag_before(flags, count, len);
    while (flags.precision > len)
    {
        write(1, "0", 1);
        count++;
        len++;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
    count += len;
    count = ft_putflag_after(flags, count, len);
    return (count);
}

int ft_putstr_flag(char *str, t_flags flags, char format)
{
    int     count;
    int     len;
    char    *null_str;

    null_str = "(null)";
    count = 0;
    (void)format;
    if (!str)
    {
        if (flags.point && flags.precision < 6)
            return (count);
        str = null_str;
    }
    len = ft_strlen(str);
    if (flags.point)
    {
        if (flags.precision >= 0 && flags.precision < len)
            len = flags.precision;
        if (flags.precision == 0)
            len = 0;
    }
    count = ft_putflag_before(flags, count, len);
    if (len > 0)
        write(1, str, len);
    count += len;
    count = ft_putflag_after(flags, count, len);
    return (count);
}

int ft_putahex(unsigned long n, t_flags flags, char format)
{
    int     count;
    char    buffer[17];
    int     i;
    int     len;

    count = 0;
    i = 0;
    if (format == 'p')
    {
        if (!n)
            return (write(1, "(nil)", 5));
        count = write(1, "0x", 2);
    }
    if (flags.point && flags.precision == 0 && !n)
        return (count);
    if (flags.hash && n && format != 'p')
    {
        if (format == 'X')
            count += write(1, "0X", 2);
        else
            count += write(1, "0x", 2);
    }
    fill_hex_buffer(n, buffer, &i, get_hex_base(format));
    len = i;
    count = ft_putflag_before(flags, count, len + count);
    while (flags.precision > len)
    {
        write(1, "0", 1);
        count++;
        len++;
    }
    count += write(1, buffer, i);
    count = ft_putflag_after(flags, count, len + count);
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
