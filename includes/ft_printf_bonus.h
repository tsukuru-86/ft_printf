/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by tkomai            #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"
# include <limits.h>

typedef struct s_pf_format
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		has_precision;
	char	conversion;
}	t_pf_format;

typedef struct s_pf_number
{
	char		digits[32];
	int			digit_count;
	const char	*prefix;
	int			prefix_count;
	int			zero_count;
	int			space_count;
}	t_pf_number;

int		ft_printf(const char *format, ...);
int		pf_parse_format_bonus(const char **format, t_pf_format *options);
int		pf_padding_bonus(char character, int count);
int		pf_add_output_bonus(int *total, int result);
int		pf_utoa_bonus(unsigned long long value, char *buffer,
			const char *base, unsigned int radix);
int		pf_print_char_bonus(t_pf_format *options, int character);
int		pf_print_string_bonus(t_pf_format *options, const char *string);
int		pf_print_percent_bonus(t_pf_format *options);
int		pf_print_nil_bonus(t_pf_format *options);
void	pf_prepare_number_bonus(t_pf_number *number, t_pf_format *options,
			unsigned long long value, int negative);
int		pf_print_signed_bonus(t_pf_format *options, int value);
int		pf_print_unsigned_bonus(t_pf_format *options, unsigned int value);
int		pf_print_pointer_bonus(t_pf_format *options, const void *pointer);

#endif
