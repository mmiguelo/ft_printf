/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 14:39:19 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/21 18:33:24 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdbool.h>
# include "../libft/libft.h"

# define FLAGS "-0#+ "
# define SPECIFIERS "cspdiuxX%"
# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"
# define DEC "0123456789"

typedef struct s_format
{
	bool	minus_flag;
	bool	zero_flag;
	bool	hash_flag;
	bool	plus_flag;
	bool	space_flag;
	int		width;
	int		precision;
	char	specifier;
}				t_format;

void	ft_init_format_bonus(t_format *fmt);
bool	ft_parse_format_bonus(t_format *fmt, const char **str);
void	ft_parse_flags_bonus(t_format *fmt, const char **str);
void	ft_parse_width_bonus(t_format *fmt, const char **str);
void	ft_parse_precision_bonus(t_format *fmt, const char **str);
bool	ft_parse_specifier_bonus(t_format *fmt, const char **str);
void	ft_resolve_flag_priorities_bonus(t_format *fmt);
int		ft_dispatch_conversion_bonus(t_format *fmt, va_list args);
int		print_ptr(t_format *fmt, void *ptr);
int		print_str(t_format *fmt, char *str);
int		print_char(t_format *fmt, char c);
int		print_nbr(t_format *fmt, unsigned long long num, char *base,
			bool is_signed);
char	*ft_get_prefix(t_format *fmt, long long num, bool is_signed);
int		ft_num_len_base(t_format *fmt, unsigned long long num, char *base);
int		ft_get_total_len(t_format *fmt, int num_len, char *prefix);
int		ft_print_padding(char c, int len);
int		ft_putnbr_base(t_format *fmt, unsigned long long num, char *base);
char	*ft_get_prefix(t_format *fmt, long long num, bool is_signed);
int		ft_printf_bonus(const char *str, ...);
int		ft_kill_bonus(const char *str);

#endif