/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:51:54 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/08 12:14:38 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	int	result;

	result = 0;
	if (!n)
		return (write(1, "(null)", 6));
	result += ft_putstr("0x");
	result += ft_puthex(n, 'x');
	return (result);
}
