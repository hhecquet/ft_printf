/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:00:37 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/17 17:11:38 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/********************************************/
/*   __ _                  _       _    __  */
/*  / _| |                (_)     | |  / _| */
/* | |_| |_     _ __  _ __ _ _ __ | |_| |_  */
/* |  _| __|   | '_ \| '__| | '_ \| __|  _| */
/* | | | |_    | |_) | |  | | | | | |_| |   */
/* |_|  \__|   | .__/|_|  |_|_| |_|\__|_|   */
/*       ______| |                          */
/*      |______|_|                          */
/********************************************/
typedef struct s_flags
{
	int		size;
	char	format;
	int		minus;
	int		plus;
	int		zero;
	int		pourcent;
	int		space;
	int		hash;
	int		point;
	int     precision;
}	t_flags;
int		ft_printf(const char *format, ...);
void	ft_parser_flag(const char **format, t_flags *flags);
void	ft_init_flags(t_flags *flags);
char	*ft_strchr(const char *s, int c);
/****************************************************/
/*  _               _      _              _       _ */
/* | |             (_)    | |            | |     | |*/
/* | |__   __ _ ___ _  ___| |_ ___   ___ | |___  | |*/
/* | '_ \ / _` / __| |/ __| __/ _ \ / _ \| / __| | |*/
/* | |_) | (_| \__ \ | (__| || (_) | (_) | \__ \ |_|*/
/* |_.__/ \__,_|___/_|\___|\__\___/ \___/|_|___/ (_)*/
/*                                                  */
/****************************************************/
int		ft_strlen(const char *s);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_count_num(long nb);
void	handle_hex_zero(char format, int *count);
void handle_double_null(t_flags flags, int *count);
/************************************************/
/*                 _ _              _       _ _ */
/*                | | |            | |     | | |*/
/*  _ __ ___  __ _| | |_ ___   ___ | |___  | | |*/
/* | '__/ _ \/ _` | | __/ _ \ / _ \| / __| | | |*/
/* | | |  __/ (_| | | || (_) | (_) | \__ \ |_|_|*/
/* |_|  \___|\__,_|_|\__\___/ \___/|_|___/ (_|_)*/
/*                                              */
/************************************************/
int		ft_putnbr_flag(long nb, t_flags flags, char format);
int		ft_putstr_flag(char *str, t_flags flags, char format);
int		ft_putahex(unsigned long n, t_flags flags, char format);
int		ft_putchar_flag(char c, t_flags flags, char format);
void	fill_hex_buffer(unsigned long n, char *buffer, int *i, char *hex);
/*******************************************/
/*             _    __ _             _ _ _ */
/*            | |  / _| |           | | | |*/
/* _ __  _   _| |_| |_| | __ _  __ _| | | |*/
/*| '_ \| | | | __| __| |/ _` |/ _` | | | |*/
/*| |_) | |_| | |_| | | | (_| | (_| |_|_|_|*/
/*| .__/ \__,_|\__|_| |_|\__,_|\__, (_|_|_)*/
/*| |                           __/ |      */
/*|_|                          |___/       */
/*******************************************/
int		ft_putflag_before(t_flags flags, int count, int len);
int		ft_putflag_after(t_flags flags, int count, int len);
void	handle_sign(long nb, t_flags flags, int *count, char format);
char	get_padding_char(t_flags flags);
char	*get_hex_base(char format);

#endif
/***************************************************/
/*  _   _                 _                        */
/* | | | |               | |                       */
/* | |_| |__   __ _ _ __ | | __  _   _  ___  _   _ */
/* | __| '_ \ / _` | '_ \| |/ / | | | |/ _ \| | | |*/
/* | |_| | | | (_| | | | |   <  | |_| | (_) | |_| |*/
/*  \__|_| |_|\__,_|_| |_|_|\_\  \__, |\___/ \__,_|*/
/*                                __/ |            */
/*                               |___/             */
/***************************************************/