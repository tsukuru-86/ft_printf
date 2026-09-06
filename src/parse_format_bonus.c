/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by tkomai            #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	initialize_options(t_pf_format *options)
{
	options->minus = 0;
	options->zero = 0;
	options->hash = 0;
	options->plus = 0;
	options->space = 0;
	options->width = 0;
	options->precision = 0;
	options->has_precision = 0;
	options->conversion = '\0';
}

static int	set_flag(char flag, t_pf_format *options)
{
	if (flag == '-')
		options->minus = 1;
	else if (flag == '0')
		options->zero = 1;
	else if (flag == '#')
		options->hash = 1;
	else if (flag == '+')
		options->plus = 1;
	else if (flag == ' ')
		options->space = 1;
	else
		return (0);
	return (1);
}

static int	parse_number(const char **format)
{
	int	value;
	int	digit;

	value = 0;
	while (**format >= '0' && **format <= '9')
	{
		digit = **format - '0';
		if (value > (INT_MAX - digit) / 10)
			value = INT_MAX;
		else
			value = value * 10 + digit;
		(*format)++;
	}
	return (value);
}

static int	valid_conversion(char conversion)
{
	return (conversion == 'c' || conversion == 's' || conversion == 'p'
		|| conversion == 'd' || conversion == 'i' || conversion == 'u'
		|| conversion == 'x' || conversion == 'X' || conversion == 'a'
		|| conversion == '%');
}

int	pf_parse_format_bonus(const char **format, t_pf_format *options)
{
	initialize_options(options);
	while (set_flag(**format, options))
		(*format)++;
	options->width = parse_number(format);
	if (**format == '.')
	{
		options->has_precision = 1;
		(*format)++;
		options->precision = parse_number(format);
	}
	options->conversion = **format;
	if (!valid_conversion(options->conversion))
		return (0);
	if (options->minus)
		options->zero = 0;
	if (options->plus)
		options->space = 0;
	(*format)++;
	return (1);
}
