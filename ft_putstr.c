/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:49:09 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/08 12:36:49 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	lenght;

	if (!str)
		return (write(1, "(null)", 6));
	lenght = ft_strlen(str);
	write(1, str, lenght);
	return (lenght);
}
