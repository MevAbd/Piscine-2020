/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:28:52 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/25 19:05:22 by mdabouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		is_double(int tab[6][6], int line, int col, int to_place)
{
	int		x;
	int		y;

	x = 1;
	y = 1;
	while (x < 5)
	{
		if (tab[x][col] == to_place)
			return (0);
		x++;
	}
	while (y < 5)
	{
		if (tab[line][y] == to_place)
			return (0);
		y++;
	}
	return (1);
}

int		check_map(int tab[6][6])
{
	int	line;
	int	col;

	line = 1;
	col = 1;
	while (col < 5)
	{
		if (is_line_ok(tab, col) == 0)
			return (0);
		col++;
	}
	while (line < 5)
	{
		if (is_col_ok(tab, line) == 0)
			return (0);
		line++;
	}
	return (1);
}

int		success(int tab[6][6])
{
	if (check_map(tab))
		return (1);
	else
		return (0);
}

int		solvi(int tab[6][6], int n, int *sol)
{
	int	to_place;

	to_place = 1;
	while (to_place <= 4)
	{
		if (n == 16)
			return (success(tab));
		if (tab[n / 4 + 1][n % 4 + 1] != 0)
			n++;
		else
		{
			if (is_double(tab, n / 4 + 1, n % 4 + 1, to_place))
			{
				tab[n / 4 + 1][n % 4 + 1] = to_place;
				if (solvi(tab, n + 1, sol))
				{
					*sol == 0 ? ft_print(tab) : 0;
					*sol = 1;
				}
			}
			tab[n / 4 + 1][n % 4 + 1] = 0;
			to_place++;
		}
	}
	return (0);
}
