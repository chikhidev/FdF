/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:08:33 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/20 02:08:34 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_rec(long n, int *len)
{
	if (n >= 10)
		ft_putnbr_rec(n / 10, len);
	*len += ft_lputchar(n % 10 + '0');
}

static void	ft_putnbr_un_rec(unsigned int n, int *len)
{
	if (n >= 10)
		ft_putnbr_un_rec(n / 10, len);
	*len += ft_lputchar(n % 10 + '0');
}

int	ft_print_dig(int digit)
{
	int	len;
	long n;

	n = (long)digit;
	len = 0;
	if (n < 0)
	{
		len += ft_lputchar('-');
		n *= -1;
	}
	ft_putnbr_rec(n, &len);
	return (len);
}

int	ft_print_uns(unsigned int digit)
{
	int	len;

	len = 0;
	ft_putnbr_un_rec(digit, &len);
	return (len);
}
