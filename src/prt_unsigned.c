/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:42:19 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/23 10:03:47 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int unsiged_len(unsigned int n)
{
    size_t digits;
    digits = 0;

    if (n == 0)
        return 1;
    
    while (n != 0)
    {
        n /= 10;
        digits += 1;
    }
    
    return digits;
}

void put_unsigned(unsigned int n)
{
    static char digits[] = "0123456789";
    
    if (n > 9)
        put_unsigned(n / 10);
    write(1, &digits[n % 10], 1);
}


int prt_unsigned(unsigned int n)
{
    put_unsigned(n);
    return ((unsiged_len(n)));
}