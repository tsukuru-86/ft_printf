/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:24:45 by tkomai            #+#    #+#             */
/*   Updated: 2024/07/10 22:17:16 by tsukuru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <ctype.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return ;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}

// // example_function: converts characters at even indices to uppercase
// void example_function(unsigned int index, char *c)
// {
//     if (index % 2 == 0 && islower((unsigned char)*c))
	// Check if the character is lowercase
//         *c = toupper((unsigned char)*c); // Convert to uppercase
// }

// int main(void)
// {
//     char str[] = "hello world";
//     ft_striteri(str, example_function);

//     printf("%s\n", str);
//     return (0);
// }