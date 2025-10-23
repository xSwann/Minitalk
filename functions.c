/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:52:47 by slatrech          #+#    #+#             */
/*   Updated: 2024/12/10 13:10:26 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long n, char *base)
{
	char	aret;
	int		len;

	len = 0;
	if (n < 0)
	{
		n = n * (-1);
		write(1, "-", 1);
		len++;
	}
	if (n >= ft_strlen(base))
	{
		len += ft_putnbr_base(n / ft_strlen(base), base);
	}
	aret = base[n % ft_strlen(base)];
	write(1, &aret, 1);
	return (len + 1);
}

int	ft_putnbr_base_uns_long(unsigned long int n, char *base)
{
	char	aret;
	int		len;

	len = 0;
	if (n >= (unsigned long int)ft_strlen(base))
	{
		len += ft_putnbr_base_uns_long(n / ft_strlen(base), base);
	}
	aret = base[n % ft_strlen(base)];
	write(1, &aret, 1);
	return (len + 1);
}

int	ft_putnbr_base_uns(unsigned int n, char *base)
{
	char	aret;
	int		len;

	len = 0;
	if (n >= (unsigned int)ft_strlen(base))
	{
		len += ft_putnbr_base_uns(n / ft_strlen(base), base);
	}
	aret = base[n % ft_strlen(base)];
	write(1, &aret, 1);
	return (len + 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char	*s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
