/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:54:33 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/25 10:18:40 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t hexa_digits(unsigned int n)
{
    size_t digits;

    digits = 0;

    if (n == 0)
        return 0;

    if (n >= 16)
    {
        n /= 16;
        digits++;
    }

    return digits;
}

static void put_hexa(unsigned int nbr, bool upper_case)
{
    static char upper_hexa[] = "0123456789ABCDEF";
    static char lower_hexa[] = "0123456789abcdef";

    if (nbr >= 16)
        put_hexa((nbr / 16), upper_case);
    if (upper_case == true)
        write(1, &upper_hexa[nbr % 16], 1);
    else
        write(1, &lower_hexa[nbr % 16], 1);
}

int	prt_hexa(unsigned int nbr, bool upper_case)
{
    put_hexa(nbr, upper_case);
    return (hexa_digits(nbr));
}