/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 08:50:25 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_conversion(char conversion, va_list *arguments)
{
	if (conversion == 'c')
		return (prt_char(va_arg(*arguments, int)));
	if (conversion == 's')
		return (prt_str(va_arg(*arguments, char *)));
	if (conversion == 'p')
		return (prt_ptr(va_arg(*arguments, void *)));
	if (conversion == 'd' || conversion == 'i')
		return (prt_int(va_arg(*arguments, int)));
	if (conversion == 'u')
		return (prt_unsigned(va_arg(*arguments, unsigned int)));
	if (conversion == 'x' || conversion == 'X')
		return (prt_hexa(va_arg(*arguments, unsigned int),
				conversion == 'X'));
	if (conversion == '%')
		return (pf_write("%", 1));
	return (-1);
}

static int	print_format(const char *format, va_list *arguments)
{
	int	printed;
	int	result;

	printed = 0;
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			result = print_conversion(format[1], arguments);
			format += 2;
		}
		else if (*format == '%')
			return (-1);
		else
			result = pf_write(format++, 1);
		if (result < 0)
			return (-1);
		printed += result;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		printed;

	if (!format)
		return (-1);
	va_start(arguments, format);
	printed = print_format(format, &arguments);
	va_end(arguments);
	return (printed);
}
