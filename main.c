/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:32:45 by tsukuru           #+#    #+#             */
/*   Updated: 2024/08/27 04:17:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

int main(void)
{
    int a = -2147483645 ;
    int *ptr = &a;
    ft_printf("ft_printfの%%p: %p\n", (void *)ptr);
    printf("printfの%%p: %p\n", (void *)ptr);
        
    ft_printf("こんにちは%s,%d年は飛躍の年にしましょう。%u\n", "Tsukuru", a, a);
    printf("こんにちは%s,%d年は飛躍の年にしましょう。%u\n", "Tsukuru", a, a);


    ft_printf("%%%%%%%%%%\n");
    printf("%%%%%%%%%%\n");
    
    ft_printf("test x: %x\ntest X: %X\n", a, a);
    printf("test x: %x\ntest X: %X\n", a, a);

    ft_printf(" %x \n", INT_MIN);
    printf(" %x \n",  INT_MIN);

    a = 42;


    ft_printf("test x: %x\ntest X: %X\n", a, a);
    printf("test x: %x\ntest X: %X\n", a, a);

    ft_printf("INT_MIN: %x\n", INT_MIN);
    printf("INT_MIN: %x\n", INT_MIN);

    ft_printf("INT_MAX: %x\n", INT_MAX);
    printf("INT_MAX: %x\n", INT_MAX);

    ft_printf("UINT_MAX: %x\n", UINT_MAX);
    printf("UINT_MAX: %x\n", UINT_MAX);

    // LONGの代わりにINTを使用
    ft_printf("Large positive int: %x\n", INT_MAX);
    printf("Large positive int: %x\n", INT_MAX);

    ft_printf("Large negative int: %x\n", INT_MIN);
    printf("Large negative int: %x\n", INT_MIN);

    // 追加のテストケース
    printf("%d\n", ft_printf("Zero: %x\n", 10));
    printf("%d\n", printf("Zero: %x\n", 10));
    
    printf("%d\n", ft_printf("Zero: %X\n", -10));
    printf("%d\n", printf("Zero: %X\n", -10));

    ft_printf("Simple hex: %x\n", 0xABCD);
    printf("Simple hex: %x\n", 0xABCD);

}