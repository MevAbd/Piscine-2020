/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdabouze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:07:48 by mdabouze          #+#    #+#             */
/*   Updated: 2020/10/25 18:13:42 by mdabouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		check_view_line(int cur, int *view, int grow)
{
	if (grow < cur && cur > 0)
	{
		(*view)++;
		grow = cur;
	}
	return (grow);
}

void	init_line(int *line, int *grow, int tab[6][6], int col)
{
	*grow = tab[1][col];
	*line = 1;
}

int		is_line_ok(int tab[6][6], int col)
{
	int view;
	int line;
	int grow;

	view = 1;
	init_line(&line, &grow, tab, col);
	while (line < 4)
	{
		grow = check_view_line(tab[line + 1][col], &view, grow);
		line++;
	}
	if (tab[0][col] != view)
		return (0);
	grow = tab[4][col];
	view = 1;
	while (line > 1)
	{
		grow = check_view_line(tab[line - 1][col], &view, grow);
		line--;
	}
	if (tab[5][col] != view)
		return (0);
	return (1);
}
