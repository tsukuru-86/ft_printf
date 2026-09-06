/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:54:12 by tsukuru           #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

# ifdef __APPLE__
#  define PF_NULL_POINTER "0x0"
#  define PF_NULL_LENGTH 3
#  define PF_SHORT_NULL_IS_EMPTY 0
# else
#  define PF_NULL_POINTER "(nil)"
#  define PF_NULL_LENGTH 5
#  define PF_SHORT_NULL_IS_EMPTY 1
# endif

int		ft_printf(const char *format, ...);
int		prt_char(int c);
int		prt_str(const char *str);
int		prt_int(int n);
int		prt_unsigned(unsigned int n);
int		prt_ptr(const void *address);
int		prt_hexa(unsigned int number, int uppercase);
int		prt_custom(void);
int		pf_write(const char *str, size_t length);
int		pf_putnbr_base(unsigned long long number, const char *base,
			unsigned int radix);
size_t	pf_strlen(const char *str);

#endif
