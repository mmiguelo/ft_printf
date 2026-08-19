/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precedences.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:44 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/19 14:26:00 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

//check if there is priorities in case of floats
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
    if (fmt->hash_flag && !(strchr("xX", fmt->specifier)))
        fmt->hash_flag = false;
    if (ft_strchr("uxXcsp%", fmt->specifier))
    {
        fmt->plus_flag = false;
        fmt->space_flag = false;
    }
}

