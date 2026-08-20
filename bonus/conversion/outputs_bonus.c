/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:11:36 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/19 14:35:29 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int print_ptr(t_format *fmt, void *ptr)
{
    if (!ptr)
    {
        return (print_str(fmt, "(nil)"));
    }
    return (print_nbr(fmt, (unsigned long long)ptr, HEX_L, false));
}

int print_char(t_format *fmt, char c)
{

}

int print_str(t_format *fmt, char *str)
{

}
/*
** Output Pipeline Order:
** [Left Space Padding] -> [Prefix (-, +, 0x)] -> [Zero Padding] -> [Digits] -> [Right Space Padding]
*/
int print_nbr(t_format *fmt, unsigned long long num, char *base,
    bool is_signed)
{
    char *prefix;
    int num_len;
    int total_len;
    int count;

    prefix = ft_get_prefix(fmt, (long long)num, is_signed);
    if (is_signed && (long long)num < 0)
        num = (unsigned long long)(-(long long)num);
    num_len = ft_num_len_base(num, base);
    total_len = ft_get_total_len(fmt, num_len, prefix);
    count = 0;
    if (!fmt->minus_flag && !fmt->zero_flag)
        count += ft_print_padding(' ', fmt->width - total_len);
    count += ft_putstr_fd(prefix, 1);
    if (!fmt->minus_flag && fmt->zero_flag)
        count += ft_print_padding('0', fmt->width - total_len);
    count += ft_print_padding('0', fmt->precision - num_len);
    count += ft_putnbr_base(num, base);
    if (fmt->minus_flag)
        count += ft_print_padding(' ', fmt->width - total_len);
    return count;
}

int ft_dispatch_conversion_bonus(t_format *fmt, va_list args)
{
    if (!fmt)
        return (0);
    if (fmt->specifier != '\0') {
        if (fmt->specifier == 'c')
            return (print_char(fmt, va_arg(args, int)));
        if (fmt->specifier == '%')
            return (print_char(fmt, '%'));
        if (fmt->specifier == 's')
            return (print_str(fmt, va_arg(args, char *)));
        if (fmt->specifier == 'd' || fmt->specifier == 'i')
            return (print_nbr(fmt, (long long)va_arg(args, int), DEC, true));
        if (fmt->specifier == 'u')
            return (print_nbr(fmt, va_arg(args, unsigned int), DEC, false));
        if (fmt->specifier == 'x')
            return (print_nbr(fmt, va_arg(args, unsigned int), HEX_L, false));
        if (fmt->specifier == 'X')
            return (print_nbr(fmt, va_arg(args, unsigned int), HEX_U, false));
        if (fmt->specifier == 'p')
            return (print_ptr(fmt, va_arg(args, void *)));
        if (fmt->specifier == 'f')
            return (print_float_bonus(fmt, va_arg(args, double)));
        return (0);
    }
}
