/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 08:50:25 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/01 20:58:27 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            switch (*str)
            {
                case 'd' : 
                {
                    別ファイルの関数呼び出し
                }
                case 's' :
                {
                    char *s = va_arg(ap, char);
                    while (*s)
                    {
                        write (1, s, 1);
                        s++;
                    }
                    break;
                }
            }
        }else
        {
            write(1, str, 1);
        }
        str++;
    }   

    va_end(ap);
    return 0;
}

int main(void)
{
    int a;
    scanf("%d", &a);
    
    ft_printf("こんにちは\n");
}