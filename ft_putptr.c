/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:51:54 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/08 14:11:13 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static int	ft_putpointerhex(unsigned long n)
{
	char	*base;
	int		result;

	result = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putpointerhex(n / 16);
		ft_putpointerhex(n % 16);
	}
	else
		write (1, &base[n], 1);
	return (result);
}

int	ft_putptr(unsigned long n)
{
	int	result;

	result = 0;
	if (!n)
		return (write(1, "(null)", 6));
	result = ft_putstr("0x");
	result += ft_count(n);
	ft_putpointerhex(n);
	return (result);
}
