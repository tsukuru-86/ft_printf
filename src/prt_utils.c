/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by tkomai            #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	pf_write(const char *str, size_t length)
{
	size_t	written;
	ssize_t	result;

	written = 0;
	while (written < length)
	{
		result = write(1, str + written, length - written);
		if (result <= 0)
			return (-1);
		written += (size_t)result;
	}
	return ((int)written);
}

int	pf_putnbr_base(unsigned long long number, const char *base,
		unsigned int radix)
{
	int	printed;
	int	result;

	printed = 0;
	if (number >= radix)
	{
		result = pf_putnbr_base(number / radix, base, radix);
		if (result < 0)
			return (-1);
		printed += result;
	}
	result = pf_write(&base[number % radix], 1);
	if (result < 0)
		return (-1);
	return (printed + result);
}
