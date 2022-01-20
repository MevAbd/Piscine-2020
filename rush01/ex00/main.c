/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:40:14 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/25 18:12:36 by mdabouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		main(int ac, char **av)
{
	int tab[6][6];
	int	sol;

	sol = 0;
	if (ft_error(av[1], ac))
		return (0);
	all_zero(tab);
	first_value(av[1], tab);
	if (check(tab) != 0)
		return (0);
	check_four(tab);
	solvi(tab, 0, &sol);
	if (sol == 0)
		write(1, "Error\n", 6);
}
