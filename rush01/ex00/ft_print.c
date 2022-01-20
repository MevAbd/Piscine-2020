/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:39:20 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/25 18:18:12 by mdabouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int tab[6][6])
{
	int col;
	int line;

	col = 1;
	line = 1;
	while (line < 5)
	{
		col = 1;
		while (col < 5)
		{
			ft_putchar(tab[line][col] + '0');
			if (col < 4)
				ft_putchar(' ');
			col++;
		}
		if (line < 5)
			ft_putchar('\n');
		line++;
	}
}
