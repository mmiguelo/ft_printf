/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 14:42:20 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/18 16:22:13 by mmiguelo         ###   ########.fr       */
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
				write(1, "ola", 3);
				//count += ft_print_args_bonus(&fmt, args);
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
