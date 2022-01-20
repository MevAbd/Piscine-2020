/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 07:57:02 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/21 11:52:20 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_sol(int tab[10][10])
{
	int		x;
	int		y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (tab[y][x] == 1)
				ft_putchar(y + '0');
			y++;
		}
		x++;
	}
	ft_putchar('\n');
}

int		ft_verif(int tab[10][10], int pos_x, int pos_y)
{
	int		x;
	int		y;

	y = -1;
	while (++y < pos_y)
		if (tab[y][pos_x] == 1)
			return (0);
	x = pos_x + 1;
	y = pos_y + 1;
	while (--y >= 0 && --x >= 0)
		if (tab[y][x] == 1)
			return (0);
	x = pos_x;
	y = pos_y;
	while (y >= 0 && x < 10)
	{
		if (tab[y][x] == 1)
			return (0);
		y--;
		x++;
	}
	return (1);
}

int		ft_sol_queen(int tab[10][10], int y, int *solution)
{
	int		x;
	int		doug;

	x = 0;
	doug = 0;
	if (y == 10)
		return (1);
	while (x < 10)
	{
		if (ft_verif(tab, x, y) == 1)
		{
			tab[y][x] = 1;
			doug = ft_sol_queen(tab, y + 1, solution);
			if (doug == 1)
			{
				(*solution)++;
				ft_print_sol(tab);
			}
			tab[y][x] = 0;
		}
		x++;
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int		tab[10][10];
	int		x;
	int		y;
	int		solution;

	x = 0;
	solution = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			tab[y][x] = 0;
			y++;
		}
		x++;
	}
	ft_sol_queen(tab, 0, &solution);
	return (solution);
}
