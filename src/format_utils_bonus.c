/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by tkomai            #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	pf_padding_bonus(char character, int count)
{
	int	printed;

	printed = 0;
	while (printed < count)
	{
		if (pf_write(&character, 1) < 0)
			return (-1);
		printed++;
	}
	return (printed);
}

int	pf_add_output_bonus(int *total, int result)
{
	if (result < 0 || *total > INT_MAX - result)
		return (0);
	*total += result;
	return (1);
}

static void	reverse_digits(char *buffer, int length)
{
	char	temporary;
	int		index;

	index = 0;
	while (index < length / 2)
	{
		temporary = buffer[index];
		buffer[index] = buffer[length - index - 1];
		buffer[length - index - 1] = temporary;
		index++;
	}
}

int	pf_utoa_bonus(unsigned long long value, char *buffer,
		const char *base, unsigned int radix)
{
	int	length;

	length = 0;
	if (value == 0)
		buffer[length++] = '0';
	while (value)
	{
		buffer[length++] = base[value % radix];
		value /= radix;
	}
	reverse_digits(buffer, length);
	return (length);
}
