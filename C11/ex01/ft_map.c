/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 08:03:54 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/28 08:35:45 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (!(ret = (int *)malloc(sizeof(int) * length)))
		return (NULL);
	while (i < length)
	{
		ret[i] = (*f)(tab[i]);
		i++;
	}
	return (ret);
}
