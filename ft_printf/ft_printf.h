/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:10:10 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/20 02:10:13 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_lputchar(int c);
int	ft_lputstr(char *str);
int	ft_print_mem(uintptr_t address);
int	ft_print_hex(uintptr_t address, int upper_case);
int	ft_print_dig(int digit);
int	ft_print_uns(unsigned int digit);
int	ft_printf(const char *format, ...);

#endif
