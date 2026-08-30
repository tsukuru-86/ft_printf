/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:42:00 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prt_char(int c)
{
	char	character;

	character = (char)c;
	return (pf_write(&character, 1));
}

int	prt_str(const char *str)
{
	if (!str)
		return (pf_write("(null)", 6));
	return (pf_write(str, pf_strlen(str)));
}
