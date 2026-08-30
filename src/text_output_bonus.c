/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_output_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by tkomai            #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_padded_text(t_pf_format *options, const char *text,
		int length)
{
	int	padding;
	int	printed;
	int	result;

	padding = options->width - length;
	if (padding < 0)
		padding = 0;
	printed = 0;
	if (!options->minus)
	{
		result = pf_padding_bonus(' ', padding);
		if (!pf_add_output_bonus(&printed, result))
			return (-1);
	}
	if (!pf_add_output_bonus(&printed, pf_write(text, length)))
		return (-1);
	if (options->minus)
	{
		result = pf_padding_bonus(' ', padding);
		if (!pf_add_output_bonus(&printed, result))
			return (-1);
	}
	return (printed);
}

int	pf_print_char_bonus(t_pf_format *options, int character)
{
	char	value;

	value = (char)character;
	return (print_padded_text(options, &value, 1));
}

int	pf_print_string_bonus(t_pf_format *options, const char *string)
{
	int	length;

	if (PF_SHORT_NULL_IS_EMPTY && !string && options->has_precision
		&& options->precision < 6)
		return (print_padded_text(options, "", 0));
	if (!string)
		string = "(null)";
	length = (int)pf_strlen(string);
	if (options->has_precision && options->precision < length)
		length = options->precision;
	return (print_padded_text(options, string, length));
}

int	pf_print_percent_bonus(t_pf_format *options)
{
	int		printed;
	char	padding;

	padding = ' ';
	if (options->zero)
		padding = '0';
	printed = 0;
	if (!options->minus
		&& !pf_add_output_bonus(&printed,
			pf_padding_bonus(padding, options->width - 1)))
		return (-1);
	if (!pf_add_output_bonus(&printed, pf_write("%", 1)))
		return (-1);
	if (options->minus
		&& !pf_add_output_bonus(&printed,
			pf_padding_bonus(' ', options->width - 1)))
		return (-1);
	return (printed);
}

int	pf_print_nil_bonus(t_pf_format *options)
{
	return (print_padded_text(options, PF_NULL_POINTER, PF_NULL_LENGTH));
}
