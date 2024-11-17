/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:21:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/17 08:56:04 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ignore_flag(char *flag)
{
	char	*tmp;
	int		i;

	i = 0;
	while (*flag)
	{
		if (*flag == '-')
		{
			tmp[i++] = '-';
			flag++; 
		}
		else if (*flag == '0')
		{
			tmp[i++] = '0';
			flag++;
		}
		if (*flag == '+' && ())
			flag++;
		if (*flag == ' ')
			flag++;
		if (*flag == '#')
			flag++;
	}
}
typedef struct s_flags
{
	int size_flag;
	char format;
	char cs;
	char pu;
	char p;
	char x;
	char di;
} t_flags;
