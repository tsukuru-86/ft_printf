/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:56:22 by tkomai            #+#    #+#             */
/*   Updated: 2024/07/10 22:17:16 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A'
			&& c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

// #include <ctype.h>

// int main(void)
// {
// 	if(ft_isalnum('1'))
// 	{
// 		printf("Perfect\n");
// 	}
// 	if(isalnum('1'))
// 	{
// 		printf("Perfect\n");
// 	}
// }
