/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:09:38 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/22 11:40:23 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	long	size;
	long	i;

	i = 0;
	size = max - min;
	if (min >= max)
		return (0);
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
