/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:34:09 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/20 12:23:38 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		*tab;
	long	size;
	long	i;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		return (-1);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (i);
}
