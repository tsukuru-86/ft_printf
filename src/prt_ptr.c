/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:19:42 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prt_ptr(const void *address)
{
	int	result;

	if (!address)
		return (pf_write(PF_NULL_POINTER, PF_NULL_LENGTH));
	result = pf_write("0x", 2);
	if (result < 0)
		return (-1);
	result = pf_putnbr_base((unsigned long long)address,
			"0123456789abcdef", 16);
	if (result < 0)
		return (-1);
	return (result + 2);
}
