/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:32:45 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/24 18:12:22 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

int main(void)
{
    // int digits = 1;
    int a = 42;
    int *ptr = &a;
    ft_printf("ft_printfの%%p: %p\n", (void *)ptr);
    printf("printfの%%p: %p\n", (void *)ptr);
        
    ft_printf("こんにちは%s,%u年は飛躍の年にしましょう。\n", "Tsukuru", 2024);

    ft_printf("test x: %x\ntest X: %X\n", a, a);
    printf("test x: %x\ntest X: %X\n", a, a);
}