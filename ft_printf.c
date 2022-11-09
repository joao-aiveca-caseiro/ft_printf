/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:33:12 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/09 18:48:16 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_args_char(int i, const char *format, va_list args)
{
	int	len;

	len = 0;
	if (format[i] == 'c' && format[i - 1] == '%')
			len += ft_printf_char(va_arg(args, int));
	else if (format[i] == 's' && format[i - 1] == '%')
			len += ft_printf_str(va_arg(args, char *));
	return (len);
}

int	ft_printf_args_num(int i, const char *format, va_list args)
{
	int	len;

	len = 0;
	if ((format[i] == 'i' || format[i] == 'd') && format[i - 1] == '%')
			len += ft_printf_int(va_arg(args, int));
	else if (format[i] == 'u' && format[i - 1] == '%')
			len += ft_printf_int(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf_args_hex(int i, const char *format, va_list args)
{
	int	len;

	len = 0;
	if ((format[i] == 'x' || format[i] == 'X') && format[i - 1] == '%')
			len += ft_printf_hex(format[i], va_arg(args, unsigned int));
	else if (format[i] == 'p' && format[i - 1] == '%')
			len += ft_printf_hexvoid(va_arg(args, unsigned long));
	return (len);
}

int	ft_printf_args_noargs(int i, const char *format)
{
	int	len;

	len = 0;
	if (format[i] != '%')
	{
		ft_putchar_fd(format[i], 1);
		len++;
	}
	return (len);
}

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
		len += ft_printf_args_char(i, format, args);
		len += ft_printf_args_num(i, format, args);
		len += ft_printf_args_hex(i, format, args);
		len += ft_printf_args_noargs(i, format);
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			len++;
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*int	ft_printf(const char *format, ...)
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
		else if (format[i] == 'u' && format[i - 1] == '%')
			len += ft_printf_int(va_arg(args, unsigned int));
		else if ((format[i] == 'x' || format[i] == 'X') && format[i - 1] == '%')
			len += ft_printf_hex(format[i], va_arg(args, unsigned int));
		else if (format[i] == 'p' && format[i - 1] == '%')
			len += ft_printf_hexvoid(va_arg(args, unsigned long));
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			len++;
			i++;
		}
		else if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}*/

/*int	main(void)
{
	ft_printf(" %p %p ", 0, 0);
	printf("%c", '\n');
	printf(" %p %p ", 0, 0);
	printf("%c", '\n');
}*/
