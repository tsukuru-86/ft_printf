/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 08:50:25 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/25 10:12:59 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int perform_conversion(char specifier, va_list ap)
{
    if (specifier == '%')
        return write(1, "%", 1);
    else if(specifier == 'c')
    {
        ft_putchar_fd(va_arg(ap, int), 1);
        return (1);
    }
    else if(specifier == 'd' || specifier == 'i')
        return (prt_int(va_arg(ap, int)));
    else if(specifier == 's')
        return (prt_str(va_arg(ap, char *)));
    else if(specifier == 'p')
        return (prt_ptr(va_arg(ap, void *)));
    else if(specifier == 'u')
        return (prt_unsigned(va_arg(ap, unsigned int)));
    else if(specifier == 'x')
        return (prt_hexa(va_arg(ap, unsigned int), false));
    else if(specifier == 'X')
        return (prt_hexa(va_arg(ap, unsigned int), true));
    else 
        return (0);
}

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
            len += perform_conversion(str[i + 1], ap);
        }else
        {
            len += write(1, &str[i], 1);
        }
        i++;
    }   

    va_end(ap);
    return (len);
}