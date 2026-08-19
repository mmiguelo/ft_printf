/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:11:36 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/19 14:35:29 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int ft_dispatch_conversion_bonus(t_format *fmt, va_list args)
{
    if (!fmt)
        return (0);
    if (fmt->specifier != NULL) {
        if (fmt->specifier == 'c' || fmt->specifier == '%')
            //ft_putchar();
        else if (fmt->specifier == 's')
            //create prototype
        else if (fmt->specifier == 'p')
            //create prototype
        else if (ft_strchr('diuxX'), fmt->specifier)
            //create prototype
        else
            ft_kill("Wrong type of conversion")
    }
}
