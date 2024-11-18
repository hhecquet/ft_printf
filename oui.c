/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:57:19 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/18 14:25:34 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*  */
/*  */

/*  */
/* 


 */
/*  */
/*  */
/* */
/*  */
/*  */

/* int	ft_putstring(char *str, t_flags flags)
{
	int		len;
	int		count;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (len >= flags.sizep && flags.point)
		len = flags.sizep;
	if (flags.format > len && !flags.minus)
		count += putformat(flags.format - len, flags);
	count += ft_putstr_len(str, len);
	if (flags.format > len && flags.minus)
		count += putformat(flags.format - len, flags);
	return (count);
} */


/*  */

