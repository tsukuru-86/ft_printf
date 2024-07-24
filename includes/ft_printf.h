/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:54:12 by tsukuru           #+#    #+#             */
/*   Updated: 2024/07/24 18:11:07 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h> 


int ft_printf(const char *str, ...);
int prt_str(char const *str);
int prt_int(int n);
int prt_unsigned(unsigned int n);
int	prt_ptr(void *adr);
int	prt_hexa(unsigned int nbr, bool upper_case);

#endif /* FT_PRINTF_H */
