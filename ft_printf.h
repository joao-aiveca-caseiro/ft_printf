/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:14:12 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/10 16:13:50 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);

int		ft_printf_char(int c);

int		ft_printf_str(char *str);

void	ft_putnbr(long n);

int		ft_printf_int(long n);

void	ft_putnbr_hex(unsigned long n, char c);

int		ft_printf_hex(char c, long n);

int		ft_printf_hexvoid(unsigned long n);

int		ft_printf_args(va_list args, char f);

#endif