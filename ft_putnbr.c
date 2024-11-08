/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:54:29 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/08 12:13:58 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	result;

	result = 0;
	if (n == -2147483648)
		result += ft_putstr("-2147483648");
	if (n < 0)
	{
		result += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		result += ft_putchar(n + '0');
	else
	{
		result += ft_putnbr(n / 10);
		result += ft_putnbr(n % 10);
	}
	return (result);
}
