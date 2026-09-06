/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by tkomai            #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_conversion(t_pf_format *options, va_list *arguments)
{
	if (options->conversion == 'c')
		return (pf_print_char_bonus(options, va_arg(*arguments, int)));
	if (options->conversion == 's')
		return (pf_print_string_bonus(options,
				va_arg(*arguments, char *)));
	if (options->conversion == 'p')
		return (pf_print_pointer_bonus(options,
				va_arg(*arguments, void *)));
	if (options->conversion == 'd' || options->conversion == 'i')
		return (pf_print_signed_bonus(options, va_arg(*arguments, int)));
	if (options->conversion == 'u' || options->conversion == 'x'
		|| options->conversion == 'X')
		return (pf_print_unsigned_bonus(options,
				va_arg(*arguments, unsigned int)));
	if (options->conversion == 'a')
		return (prt_custom());
	if (options->conversion == '%')
		return (pf_print_percent_bonus(options));
	return (-1);
}

static int	print_format(const char *format, va_list *arguments)
{
	t_pf_format	options;
	int			printed;
	int			result;

	printed = 0;
	while (*format)
	{
		if (*format != '%')
			result = pf_write(format++, 1);
		else
		{
			format++;
			if (!pf_parse_format_bonus(&format, &options))
				return (-1);
			result = print_conversion(&options, arguments);
		}
		if (!pf_add_output_bonus(&printed, result))
			return (-1);
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
