/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:32:45 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/25 21:08:47 by tkomai           ###   ########.fr       */
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


    ft_printf("test x: %x\ntest X: %X\n", a, a);
    printf("test x: %x\ntest X: %X\n", a, a);
}