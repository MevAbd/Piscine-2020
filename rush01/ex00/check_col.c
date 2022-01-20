/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdabouze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:07:10 by mdabouze          #+#    #+#             */
/*   Updated: 2020/10/25 18:11:07 by mdabouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		check_view_col(int cur, int *view, int grow)
{
	if (grow < cur && cur > 0)
	{
		(*view)++;
		grow = cur;
	}
	return (grow);
}

void	init_col(int *view, int *grow, int tab[6][6], int line)
{
	*grow = tab[line][1];
	*view = 1;
}

int		is_col_ok(int tab[6][6], int line)
{
	int	view;
	int col;
	int grow;

	col = 1;
	init_col(&view, &grow, tab, line);
	while (col < 4)
	{
		grow = check_view_col(tab[line][col + 1], &view, grow);
		col++;
	}
	if (tab[line][0] != view)
		return (0);
	grow = tab[line][4];
	view = 1;
	while (col > 1)
	{
		grow = check_view_col(tab[line][col - 1], &view, grow);
		col--;
	}
	if (tab[line][5] != view)
		return (0);
	return (1);
}
