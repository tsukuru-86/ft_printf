/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:11:53 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/25 10:25:35 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>
// #include <unistd.h>
// #include <stdarg.h>
// #include <limits.h>
// #include <stdbool.h> 

static size_t int_digits(int n)
{
    printf("int_digits called with n = %d\n", n);
    size_t digits;
    digits = 0;

    if (n == 0)
        return 1;

    if (n < 0)
        digits += 1;
    
    while (n != 0)
    {
        n /= 10;
        digits += 1;
    }
    return digits;
}

static void put_digits(int n)
{
    printf("put_digits called with n = %d\n", n);
    static char digits[] = "0123456789";

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    
    if (n > 9)
        put_digits(n / 10);
    write(1, &digits[n % 10], 1);
}

int prt_int(int n)
{
    printf("prt_int called with n = %d\n", n); // デバッグ出力
    int len;
    
    len = int_digits(n);
    if (n == INT_MIN)
        return write(1, "-2147483648", 11);
    // // ft_putnbr_fd(len, 1);
    put_digits(n);

    return (len);
}

// int main(void)
// {
//     int n = -22;
//     prt_int(n);
// }
