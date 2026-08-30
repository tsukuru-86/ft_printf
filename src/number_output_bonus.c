/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_output_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by tkomai            #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_number(t_pf_number *number, t_pf_format *options)
{
	int	printed;

	printed = 0;
	if (!options->minus && !pf_add_output_bonus(&printed,
			pf_padding_bonus(' ', number->space_count)))
		return (-1);
	if (!pf_add_output_bonus(&printed, pf_write(number->prefix,
				number->prefix_count)))
		return (-1);
	if (!pf_add_output_bonus(&printed,
			pf_padding_bonus('0', number->zero_count))
		|| !pf_add_output_bonus(&printed, pf_write(number->digits,
				number->digit_count)))
		return (-1);
	if (options->minus && !pf_add_output_bonus(&printed,
			pf_padding_bonus(' ', number->space_count)))
		return (-1);
	return (printed);
}

int	pf_print_signed_bonus(t_pf_format *options, int value)
{
	t_pf_number		number;
	unsigned int	magnitude;

	if (value < 0)
		magnitude = (unsigned int)(-(value + 1)) + 1;
	else
		magnitude = (unsigned int)value;
	pf_prepare_number_bonus(&number, options, magnitude, value < 0);
	return (print_number(&number, options));
}

int	pf_print_unsigned_bonus(t_pf_format *options, unsigned int value)
{
	t_pf_number	number;

	pf_prepare_number_bonus(&number, options, value, 0);
	return (print_number(&number, options));
}

int	pf_print_pointer_bonus(t_pf_format *options, const void *pointer)
{
	t_pf_number	number;

	if (!pointer)
		return (pf_print_nil_bonus(options));
	pf_prepare_number_bonus(&number, options,
		(unsigned long long)pointer, 0);
	return (print_number(&number, options));
}
