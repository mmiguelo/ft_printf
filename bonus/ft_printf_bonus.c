/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 14:42:20 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/21 11:07:57 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_bonus(const char *str, ...)
{
	t_format fmt;
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0') {
			str++;
			ft_init_format_bonus(&fmt);
			if (ft_parse_format_bonus(&fmt, &str))
				count += ft_dispatch_conversion_bonus(&fmt, args);
		}
		else if (*str != '%') {
			count += ft_putchar(*str);
			str++;
		}
		else
			str++;
	}
	va_end(args);
	return (count);
}
