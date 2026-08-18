/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:23:19 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/18 16:46:52 by mmiguelo         ###   ########.fr       */
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

int ft_putchar(const char c)
{
    write(1, &c, 1);
    return 1;
}
