/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:03:29 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/08 11:22:57 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // variadic
# include <string.h>
# include <unistd.h> // write
# include <stdio.h>
# include <stdlib.h> //free malloc

int	ft_printf(const char *, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int n, char c);
int	ft_putptr(unsigned long n);
int	ft_pututoa(unsigned int n);


#endif