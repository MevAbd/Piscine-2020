/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 08:11:55 by rgeny             #+#    #+#             */
/*   Updated: 2020/10/17 16:13:01 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush_line(char first_char, char space_char, char last_char, int x)
{
	int pos_x;

	if (x > 0)
	{
		ft_putchar(first_char);
		pos_x = 2;
		while (pos_x < x)
		{
			ft_putchar(space_char);
			pos_x++;
		}
		if (pos_x == x)
			ft_putchar(last_char);
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	int pos_y;

	if (y > 0)
	{
		rush_line('o', '-', 'o', x);
	}
	pos_y = 2;
	while (pos_y < y)
	{
		rush_line('|', ' ', '|', x);
		pos_y++;
	}
	if (pos_y == y)
	{
		rush_line('o', '-', 'o', x);
	}
}
