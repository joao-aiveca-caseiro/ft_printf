/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:33:12 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/08 16:58:20 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// chars

int	ft_printf_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

// base 10 numbers

static int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(long n)
{
	ft_numlen(n);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar_fd(n + 48, 1);
}

int	ft_printf_int(long n)
{
	ft_putnbr(n);
	return (ft_numlen(n));
}

// base 16 numbers

void	ft_putnbr_hex(long n, char c)
{
	ft_numlen(n);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar_fd(n + 48, 1);
}

int	ft_printf_hexlow(long n)
{
	ft_putnbr_hex(n, l);
	return (ft_numlen_hex(n));
}

int	ft_printf_hexupp(long n)
{
	ft_putnbr_hex(n, u);
	return (ft_numlen_hex(n));
}

////////////

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == 'c' && format[i - 1] == '%')
			len += ft_printf_char(va_arg(args, int));
		else if (format[i] == 's' && format[i - 1] == '%')
			len += ft_printf_str(va_arg(args, char *));
		else if ((format[i] == 'i' || format[i] == 'd') && format[i - 1] == '%')
			len += ft_printf_int(va_arg(args, int));
		else if ((format[i] == 'u' && format[i - 1]))
			len += ft_printf_int(va_arg(args, unsigned int));
		else if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	ft_printf(" %i ", -1);
	printf("%c", '\n');
	printf(" %i ", -1);
	printf("%c", '\n');
}*/
