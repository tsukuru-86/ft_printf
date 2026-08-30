/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by tkomai            #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	convert_number(t_pf_number *number, t_pf_format *options,
		unsigned long long value)
{
	const char		*base;
	unsigned int	radix;

	base = "0123456789";
	radix = 10;
	if (options->conversion == 'x' || options->conversion == 'p')
	{
		base = "0123456789abcdef";
		radix = 16;
	}
	else if (options->conversion == 'X')
	{
		base = "0123456789ABCDEF";
		radix = 16;
	}
	return (pf_utoa_bonus(value, number->digits, base, radix));
}

static void	set_prefix(t_pf_number *number, t_pf_format *options,
		unsigned long long value, int negative)
{
	number->prefix = "";
	if (negative)
		number->prefix = "-";
	else if ((options->conversion == 'd' || options->conversion == 'i')
		&& options->plus)
		number->prefix = "+";
	else if ((options->conversion == 'd' || options->conversion == 'i')
		&& options->space)
		number->prefix = " ";
	else if (options->conversion == 'p')
		number->prefix = "0x";
	else if (options->hash && value && options->conversion == 'x')
		number->prefix = "0x";
	else if (options->hash && value && options->conversion == 'X')
		number->prefix = "0X";
	number->prefix_count = (int)pf_strlen(number->prefix);
}

static void	set_padding(t_pf_number *number, t_pf_format *options)
{
	number->zero_count = 0;
	if (options->has_precision
		&& options->precision > number->digit_count)
		number->zero_count = options->precision - number->digit_count;
	number->space_count = options->width - number->prefix_count
		- number->zero_count - number->digit_count;
	if (number->space_count < 0)
		number->space_count = 0;
	if (options->zero && !options->has_precision && !options->minus)
	{
		number->zero_count += number->space_count;
		number->space_count = 0;
	}
}

void	pf_prepare_number_bonus(t_pf_number *number, t_pf_format *options,
		unsigned long long value, int negative)
{
	number->digit_count = convert_number(number, options, value);
	if (value == 0 && options->has_precision && options->precision == 0
		&& options->conversion != 'p')
		number->digit_count = 0;
	set_prefix(number, options, value, negative);
	set_padding(number, options);
}
