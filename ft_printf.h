/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:13:33 by slatrech          #+#    #+#             */
/*   Updated: 2024/12/10 13:17:07 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h> 
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_putnbr_base(long n, char *base);

int	ft_putnbr_base_uns_long(unsigned long int n, char *base);

int	ft_putnbr_base_uns(unsigned int n, char *base);

int	ft_strlen(char *s);

int	ft_putstr(char	*s);

#endif