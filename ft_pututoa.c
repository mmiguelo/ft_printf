/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:31:07 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/08 12:15:00 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_intlenght(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	ft_pututoa(unsigned int n)
{
	int	*str;
	int	lenght;
	int	i;
	int	result;

	result = 0;
	lenght = ft_intlenght(n);
	str = malloc(sizeof(char) * (lenght + 1));
	if (!n)
		return (0);
	str[lenght--] = '\0';
	while (n != 0)
	{
		str[lenght--] = n % 10;
		n = n / 10;
	}
	result = ft_putstr(str);
	free(str);
	return (result);
}
