/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:24:25 by slatrech          #+#    #+#             */
/*   Updated: 2025/01/30 11:41:38 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pcase(void	*p)
{
	int	l;

	l = 0;
	if (p == NULL)
	l += ft_putstr("(nil)");
	else
	{
		l += ft_putstr("0x");
		l += ft_putnbr_base_uns_long((unsigned long)p, "0123456789abcdef");
	}
	return (l);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	caller(const char c, va_list args)
{
	int	l;

	l = 0;
	if (c == '%')
		l += ft_putchar('%');
	if (c == 'd' || c == 'i')
		l += ft_putnbr_base(va_arg(args, int), "0123456789");
	if (c == 'u')
		l += ft_putnbr_base_uns(va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
		l += ft_putnbr_base_uns(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		l += ft_putnbr_base_uns(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == 'c')
		l += ft_putchar(va_arg(args, int));
	if (c == 's')
		l += ft_putstr((char *)va_arg(args, char *));
	if (c == 'p')
		l += pcase(va_arg(args, void *));
	return (l);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			len += caller(*format, args);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}	
	va_end(args);
	return (len);
}

/* int main()
{
	ft_printf("");
	printf("0");
} */