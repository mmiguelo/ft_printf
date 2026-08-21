/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:11:36 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/21 18:52:44 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	print_ptr(t_format *fmt, void *ptr)
{
	int	original_precision;
	int	ret;

	if (!ptr)
	{
		original_precision = fmt->precision;
		fmt->precision = -1;
		ret = print_str(fmt, "(nil)");
		fmt->precision = original_precision;
		return (ret);
	}
	return (print_nbr(fmt, (unsigned long long)ptr, HEX_L, false));
}

int	print_char(t_format *fmt, char c)
{
	int	count;

	count = 0;
	if (!fmt->minus_flag)
		count += ft_print_padding(' ', fmt->width - 1);
	count += write(1, &c, 1);
	if (fmt->minus_flag)
		count += ft_print_padding(' ', fmt->width - 1);
	return (count);
}

int	print_str(t_format *fmt, char *str)
{
	int	len;
	int	count;

	if (!str)
	{
		if (fmt->precision >= 0 && fmt->precision < 6)
			str = "";
		else
			str = "(null)";
	}
	len = ft_strlen(str);
	if (fmt->precision >= 0 && fmt->precision < len)
		len = fmt->precision;
	count = 0;
	if (!fmt->minus_flag)
		count += ft_print_padding(' ', fmt->width - len);
	count += write(1, str, len);
	if (fmt->minus_flag)
		count += ft_print_padding(' ', fmt->width - len);
	return (count);
}

/*
** Output Pipeline Order:
** [Left Space Padding] -> [Prefix (-, +, 0x)] ->
**  -> [Zero Padding] -> [Digits] -> [Right Space Padding]
*/
int	print_nbr(t_format *fmt, unsigned long long num, char *base,
	bool is_signed)
{
	char	*prefix;
	int		num_len;
	int		total_len;
	int		count;

	prefix = ft_get_prefix(fmt, (long)num, is_signed);
	if (is_signed && (long)num < 0)
		num = (unsigned long long)(-(long)num);
	num_len = ft_num_len_base(fmt, num, base);
	total_len = ft_get_total_len(fmt, num_len, prefix);
	count = 0;
	if (!fmt->minus_flag && !fmt->zero_flag)
		count += ft_print_padding(' ', fmt->width - total_len);
	count += write(1, prefix, ft_strlen(prefix));
	if (!fmt->minus_flag && fmt->zero_flag)
		count += ft_print_padding('0', fmt->width - total_len);
	count += ft_print_padding('0', fmt->precision - num_len);
	count += ft_putnbr_base(fmt, num, base);
	if (fmt->minus_flag)
		count += ft_print_padding(' ', fmt->width - total_len);
	return (count);
}
