/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:49:09 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/07 18:47:17 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
	{
		result += ft_putstr("(null)");
		return (1);
	}
	while (str[i])
	{
		result += ft_putchar(str[i]);
		i++;
	}
	return (1);
}
