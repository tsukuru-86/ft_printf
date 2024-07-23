/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:42:00 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/10 21:28:22 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int prt_str(char const *str)
{
    if (str == NULL)
        return write(1, "(null)", 6);
    else
        return write(1, str, ft_strlen(str));
}