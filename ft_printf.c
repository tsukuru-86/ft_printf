/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 08:50:25 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/03 17:24:46 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"



int ft_printf(const char *str, ...)
{
    int i;
    int len;
    va_list ap;
    if (!str)
        return (0);
    
    i = 0;
    len = 0;
    va_start(ap, str);
    
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            len += 関数名(str[i], ap);
        }else
        {
            len += write(1, &str[i], 1);
        }
        i++;
    }   

    va_end(ap);
    return (len);
}

int main(void)
{
    int a;
    scanf("%d", &a);
    
    ft_printf("こんにちは\n");
}