/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:21:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/17 14:19:23 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putflag_before( t_flags flags, int count, int len)
{
	if (flags.zero == 1 && flags.minus == 0 && (flags.format == 'c'
			|| flags.format == 's'))
	{
		while (len < flags.size)
		{
			count += write(1, " ", 1);
			flags.size--;
		}
	}
	else if (flags.zero == 1 && flags.minus == 0)
	{
		while (len < flags.size)
		{
			count += write(1, " ", 1);
			flags.size--;
		}
	}
	return (count);
}

int	ft_putflag_after( t_flags flags, int count, int len)
{
	if (flags.minus == 1)
	{
		while (len < flags.size)
		{
			count += write(1, " ", 1);
			flags.size--;
		}
	}
	return (count);
}
