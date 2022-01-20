/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:21:56 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/18 15:03:53 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_error(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int			nb;
	unsigned int			size;

	size = check_error(base);
	if (size > 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nb = -nbr;
		}
		else
			nb = nbr;
		if (nb >= size)
		{
			ft_putnbr_base(nb / size, base);
			ft_putnbr_base(nb % size, base);
		}
		else
			ft_putchar(base[nb]);
	}
}
