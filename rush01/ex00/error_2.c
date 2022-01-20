/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youerdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:30:29 by youerdan          #+#    #+#             */
/*   Updated: 2020/10/25 18:30:37 by youerdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		check_line(int tab[6][6], int line, int col)
{
	int	sum;

	sum = 0;
	while (col < 5)
	{
		sum = sum + tab[line][col];
		col++;
	}
	if (sum > 10)
		return (1);
	return (0);
}

int		check_col(int tab[6][6], int line, int col)
{
	int	sum;

	sum = 0;
	while (line < 5)
		sum = sum + tab[line++][col];
	if (sum > 10)
		return (1);
	return (0);
}

int		check(int tab[6][6])
{
	int ret;

	ret = 0;
	if (check_line(tab, 0, 1) == 1)
		ret = 1;
	if (check_line(tab, 5, 1) == 1)
		ret = 1;
	if (check_col(tab, 1, 0) == 1)
		ret = 1;
	if (check_col(tab, 1, 5) == 1)
		ret = 1;
	if (ret)
		write(1, "Error\n", 6);
	return (ret);
}
