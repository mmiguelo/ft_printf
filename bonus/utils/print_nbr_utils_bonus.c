/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:23:19 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/21 17:15:54 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_get_prefix(t_format *fmt, long long num, bool is_signed)
{
	if (is_signed && num < 0)
		return ("-");
	if (is_signed && fmt->plus_flag)
		return ("+");
	if (is_signed && fmt->space_flag)
		return (" ");
	if (fmt->hash_flag && num != 0 && fmt->specifier == 'x')
		return ("0x");
	if (fmt->hash_flag && num != 0 && fmt->specifier == 'X')
		return ("0X");
	if (fmt->specifier == 'p' && num != 0)
		return ("0x");
	return ("");
}

int	ft_num_len_base(t_format *fmt, unsigned long long num, char *base)
{
	int					len;
	unsigned long long	base_len;

	if (num == 0 && fmt->precision == 0)
		return (0);
	if (num == 0)
		return (1);
	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	while (num > 0)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

int	ft_get_total_len(t_format *fmt, int num_len, char *prefix)
{
	int	total_length;
	int	prefix_length;

	total_length = num_len;
	if (fmt->precision > num_len)
		total_length = fmt->precision;
	prefix_length = 0;
	if (prefix)
	{
		while (prefix[prefix_length])
			prefix_length++;
	}
	total_length += prefix_length;
	return (total_length);
}

int	ft_print_padding(char c, int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		count += write(1, &c, 1);
		len--;
	}
	return (count);
}

int	ft_putnbr_base(t_format *fmt, unsigned long long num, char *base)
{
	int					count;
	unsigned long long	base_len;

	if (num == 0 && fmt->precision == 0)
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	count = 0;
	if (num >= base_len)
		count += ft_putnbr_base(fmt, num / base_len, base);
	count += write(1, &base[num % base_len], 1);
	return (count);
}
