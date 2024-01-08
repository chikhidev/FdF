/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:24:15 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/19 18:24:17 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	switcher(const char *str, va_list params, int *i, int *len)
{
	*i += 1;
	if (str[*i] == 'c')
		*len += ft_lputchar(va_arg(params, int));
	else if (str[*i] == 's')
		*len += ft_lputstr(va_arg(params, char *));
	else if (str[*i] == 'p')
		*len += ft_print_mem((uintptr_t)va_arg(params, void *));
	else if (str[*i] == 'd' || str[*i] == 'i')
		*len += ft_print_dig(va_arg(params, int));
	else if (str[*i] == 'u')
		*len += ft_print_uns(va_arg(params, unsigned int));
	else if (str[*i] == 'x')
		*len += ft_print_hex((unsigned)va_arg(params, int), 0);
	else if (str[*i] == 'X')
		*len += ft_print_hex((unsigned)va_arg(params, int), 1);
	else if (str[*i] == '%')
		*len += ft_lputchar('%');
	else if (str[*i] == '\0')
		return (0);
	else
		*len += ft_lputchar(str[*i]);
	return (1);
}

static int	manage_args(const char *str, va_list params)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (switcher(str, params, &i, &len) == 0)
				break ;
		}
		else
			len += ft_lputchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	params;

	va_start(params, format);
	len = manage_args(format, params);
	return (len);
}
