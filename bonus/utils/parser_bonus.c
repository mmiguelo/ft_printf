/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:18:27 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/18 15:47:08 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_parse_flags_bonus(t_format *fmt, const char **str)
{
    if (!fmt || !str || !*str)
        return;
    while (**str && ft_strchr(FLAGS, **str))
    {
        if (**str == '-')
            fmt->minus_flag = true;
        else if (**str == '0')
            fmt->zero_flag = true;
        else if (**str == '#')
            fmt->hash_flag = true;
        else if (**str == '+')
            fmt->plus_flag = true;
        else if (**str == ' ')
            fmt->space_flag = true;
        (*str)++;
    }
}

void    ft_parse_width_bonus(t_format *fmt, const char **str)
{
    if (!fmt || !str || !*str)
        return ;
    while (**str >= '0' && **str <= '9')
    {
        fmt->width = (fmt->width * 10) + (**str - '0');
        (*str)++;
    }
}

void    ft_parse_precision_bonus(t_format *fmt, const char **str)
{
    if (!fmt || !str || !*str)
        return ;
    if (**str == '.') {
        (*str)++;
        fmt->precision = 0;
        while (**str >= '0' && **str <= '9') {
            fmt->precision = (fmt->precision * 10) + (**str - '0');
            (*str)++; 
        }
    }
}

bool    ft_parse_specifier_bonus(t_format *fmt, const char **str) {
    if (!fmt || !str || !*str)
        return false;
    if (ft_strchr(SPECIFIERS, **str))
    {
        fmt->specifier = **str;
        (*str)++;
        return true;
    }
    return false;
}

bool    ft_parse_format_bonus(t_format *fmt, const char **str)
{
    if (!fmt || !str || !*str)
        return false;
    ft_parse_flags_bonus(fmt, str);
    ft_parse_width_bonus(fmt, str);
    ft_parse_precision_bonus(fmt, str);
    if (!ft_parse_specifier_bonus(fmt, str))
        return false;
    ft_resolve_flag_priorities_bonus(fmt);
    return true;
}
