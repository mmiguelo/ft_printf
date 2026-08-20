/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:44 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/19 14:26:00 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void ft_init_format_bonus(t_format *fmt)
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

void ft_resolve_flag_priorities_bonus(t_format *fmt)
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
