/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:08:08 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/20 02:08:10 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_converter(unsigned char to_convert, int to_upper)
{
	const char	*base = "0123456789abcdef";
	char		c;

	c = base[to_convert];
	return (ft_lputchar(c - (to_upper * 32 * (c >= 'a' && c <= 'f'))));
}

int	ft_print_hex(uintptr_t address, int upper_case)
{
	int			len;

	len = 0;
	if (address > 15)
		len += ft_print_hex(address / 16, upper_case);
	len += hex_converter(address % 16, upper_case);
	return (len);
}

int	ft_print_mem(uintptr_t address)
{
	int			len;

	len = 0;
	len += ft_lputstr("0x");
	if (address > 15)
		len += ft_print_hex(address / 16, 0);
	len += hex_converter(address % 16, 0);
	return (len);
}
