/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 14:39:19 by mmiguelo          #+#    #+#             */
/*   Updated: 2026/08/18 16:21:53 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

#include <stdbool.h>
#include "../libft/libft.h"

# define FLAGS "-0#+ "
# define SPECIFIERS "cspdiuxX%"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"

typedef struct s_format {
    bool minus_flag;
    bool zero_flag;
    bool hash_flag;
    bool plus_flag;
    bool space_flag;
    int width;
    int precision;
    char specifier;
} t_format;

void	ft_init_bonus(t_format *fmt);
void	ft_init_format_bonus(t_format *fmt);
bool    ft_parse_format_bonus(t_format *fmt, const char **str);
void	ft_parse_flags_bonus(t_format *fmt, const char **str);
void    ft_parse_width_bonus(t_format *fmt, const char **str);
void    ft_parse_precision_bonus(t_format *fmt, const char **str);
bool    ft_parse_specifier_bonus(t_format *fmt, const char **str);
void    ft_resolve_flag_priorities_bonus(t_format *fmt);
int	    ft_printf_bonus(const char *str, ...);
int     ft_putchar(const char c);
int	    ft_kill_bonus(const char *str);

#endif