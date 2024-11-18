/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basictools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:50:56 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/18 10:12:25 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(const char *s)
{
    int j;

    if (!s)
        return (0);
    j = 0;
    while (s && s[j])
        j++;
    return (j);
}

int	ft_count_num(long nb)
{
    int	count;

    if (nb == 0)
        return (1);
    count = 0;
    if (nb < 0)
    {
        nb = nb * -1;
        count++;
    }
    while (nb >= 10)
    {
        nb = nb / 10;
        count++;
    }
    return (count + 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
    long	n;

    n = nb;
    if (n < 0)
    {
        n = n * -1;
        ft_putchar('-');
    }
    if (n >= 10)
    {
        ft_putnbr(n / 10);
    }
    ft_putchar((n % 10) + '0');
}

void handle_hex_zero(char format, int *count)
{
    if (format == 'p')
    {
        *count = write(1, "0x0", 3);
        return;
    }
    *count = write(1, "0", 1);
}
