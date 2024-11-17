/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:21:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/17 16:42:05 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_padding_char(t_flags flags)
{
    if (flags.zero && !flags.minus)
        return ('0');
    return (' ');
}

int ft_putflag_before(t_flags flags, int count, int len)
{
    char pad;
    int size;

    pad = get_padding_char(flags);
    size = flags.size;
    if (!flags.minus)
    {
        while (len < size)
        {
            write(1, &pad, 1);
            count++;
            len++;
        }
    }
    return (count);
}

int ft_putflag_after(t_flags flags, int count, int len)
{
    if (flags.minus)
        while (len < flags.size)
        {
            count += write(1, " ", 1);
            len++;
        }
    return (count);
}

void	handle_sign(long nb, t_flags flags, int *count, char format)
{
	if (format != 'u' && nb > 0 && flags.plus)
		*count += write(1, "+", 1);
	else if (format != 'u' && nb > 0 && flags.space)
		*count += write(1, " ", 1);
}

char *get_hex_base(char format)
{
	if (format == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}
void fill_hex_buffer(unsigned long n, char *buffer, int *i, char *hex)
{
    char temp[17];
    int j;

    j = 0;
    if (n == 0)
    {
        buffer[*i] = '0';
        (*i)++;
        return;
    }
    while (n > 0)
    {
        temp[j++] = hex[n % 16];
        n /= 16;
    }
    while (j > 0)
        buffer[(*i)++] = temp[--j];
}