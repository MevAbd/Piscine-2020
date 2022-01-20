/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:40:33 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/14 14:44:36 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	only_one(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(i + 48);
		i++;
		if (i <= 9)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_tab(int *tab, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (tab[i - 1] >= tab[i])
			return ;
		i++;
	}
	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + 48);
		i++;
	}
	if (tab[0] < 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[10];

	i = -1;
	if (n == 1)
		only_one();
	while (++i < n)
		tab[i] = i;
	while (tab[0] <= 10 - n && n > 1 && n < 10)
	{
		ft_print_tab(tab, n);
		tab[n - 1]++;
		i = n;
		while (i > 1)
		{
			i--;
			if (tab[i] > 9)
			{
				tab[i - 1]++;
				tab[i] = 0;
			}
		}
	}
}
