/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:33:12 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/07 17:52:19 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	ft_printf(" NULL %s NULL ", NULL);
	printf("%c", '\n');
	printf(" NULL %s NULL ", NULL);
	printf("%c", '\n');
}*/
