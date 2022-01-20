/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youerdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:16:26 by youerdan          #+#    #+#             */
/*   Updated: 2020/10/25 18:12:15 by mdabouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	all_zero(int tab[6][6])
{
	int col;
	int line;

	line = 0;
	while (line < 6)
	{
		col = 0;
		while (col < 6)
		{
			tab[line][col] = 0;
			col++;
		}
		line++;
	}
}

void	first_value(char *str, int tab[6][6])
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i <= 6)
			tab[0][i / 2 + 1] = str[i] - '0';
		else if (i <= 14)
			tab[5][i / 2 - 3] = str[i] - '0';
		else if (i <= 22)
			tab[i / 2 - 7][0] = str[i] - '0';
		else if (i <= 30)
			tab[i / 2 - 11][5] = str[i] - '0';
		i += 2;
	}
}

void	fill_col(int tab[6][6], int col, int line)
{
	int value;

	if (line == 0)
	{
		value = 1;
		while (value < 5)
		{
			tab[line + value][col] = value;
			value++;
		}
	}
	if (line == 5)
	{
		value = 4;
		while (value > 0)
		{
			tab[line - value][col] = value;
			value--;
		}
	}
}

void	fill_line(int tab[6][6], int col, int line)
{
	int value;

	if (col == 0)
	{
		value = 1;
		while (value < 5)
		{
			tab[line][col + value] = value;
			value++;
		}
	}
	if (col == 5)
	{
		value = 4;
		while (value > 0)
		{
			tab[line][col - value] = value;
			value--;
		}
	}
}

void	check_four(int tab[6][6])
{
	int line;
	int col;

	line = 0;
	while (line < 6)
	{
		col = 0;
		while (col < 6)
		{
			if ((line == 0 && tab[line][col] == 4) ||
				(line == 5 && tab[line][col] == 4))
				fill_col(tab, col, line);
			if ((col == 0 && tab[line][col] == 4) ||
				(col == 5 && tab[line][col] == 4))
				fill_line(tab, col, line);
			col++;
		}
		line++;
	}
}
