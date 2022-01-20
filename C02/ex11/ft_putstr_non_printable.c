/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:39:21 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/15 22:31:22 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(int nb)
{
	char	*base;

	base = "0123456789abcdefg";
	if (nb >= 16)
	{
		ft_print_hex(nb / 16);
		ft_print_hex(nb % 16);
	}
	else
		ft_putchar(base[nb % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] <= '~')
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			if (str[i] <= 16)
				ft_putchar('0');
			ft_print_hex((int)str[i]);
		}
		i++;
	}
}
