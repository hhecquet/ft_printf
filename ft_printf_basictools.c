/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basictools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:50:56 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/15 08:58:45 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		j++;
	}
	return (j);
}
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1)
}
int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return (c + 32);
	}
	return (c);
}
void	ft_putstr(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}