/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:44 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/21 18:33:17 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_init_format_bonus(t_format *fmt)
{
	fmt->minus_flag = false;
	fmt->zero_flag = false;
	fmt->hash_flag = false;
	fmt->plus_flag = false;
	fmt->space_flag = false;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->specifier = '\0';
}

int	ft_kill_bonus(const char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	ft_resolve_flag_priorities_bonus(t_format *fmt)
{
	if (!fmt)
		return ;
	if (fmt->minus_flag && fmt->zero_flag)
		fmt->zero_flag = false;
	if (fmt->plus_flag && fmt->space_flag)
		fmt->space_flag = false;
	if (ft_strchr("diuxX", fmt->specifier) && fmt->precision >= 0)
		fmt->zero_flag = false;
	if (fmt->hash_flag && !(ft_strchr("xX", fmt->specifier)))
		fmt->hash_flag = false;
	if (!ft_strchr("dif", fmt->specifier))
	{
		fmt->plus_flag = false;
		fmt->space_flag = false;
	}
}

int	ft_dispatch_conversion_bonus(t_format *fmt, va_list args)
{
	if (!fmt)
		return (0);
	if (fmt->specifier != '\0')
	{
		if (fmt->specifier == 'c')
			return (print_char(fmt, va_arg(args, int)));
		if (fmt->specifier == '%')
			return (print_char(fmt, '%'));
		if (fmt->specifier == 's')
			return (print_str(fmt, va_arg(args, char *)));
		if (fmt->specifier == 'd' || fmt->specifier == 'i')
			return (print_nbr(fmt, va_arg(args, int), DEC, true));
		if (fmt->specifier == 'u')
			return (print_nbr(fmt, va_arg(args, unsigned int), DEC, false));
		if (fmt->specifier == 'x')
			return (print_nbr(fmt, va_arg(args, unsigned int), HEX_L, false));
		if (fmt->specifier == 'X')
			return (print_nbr(fmt, va_arg(args, unsigned int), HEX_U, false));
		if (fmt->specifier == 'p')
			return (print_ptr(fmt, va_arg(args, void *)));
		//if (fmt->specifier == 'f')
		//	return (print_float_bonus(fmt, va_arg(args, double)));
	}
	return (0);
}
