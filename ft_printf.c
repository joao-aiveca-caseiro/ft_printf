/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:33:12 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/07 04:31:19 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("dcff\n");
	printf("dcff\n");
}
