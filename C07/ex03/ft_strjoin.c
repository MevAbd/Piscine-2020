/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:47:38 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/27 07:24:35 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(int size, char **strs, char *sep)
{
	int		x;
	int		y;
	int		nb_char;

	x = 0;
	y = 0;
	nb_char = 0;
	if (size <= 0)
		return (1);
	while (y < size)
	{
		while (strs[y][x])
			x++;
		nb_char = nb_char + x;
		y++;
		x = 0;
	}
	y = 0;
	while (sep[y])
		y++;
	y = y * (size - 1);
	nb_char = nb_char + y;
	return (nb_char + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	long	nb_char;
	char	*ret;
	int		x;
	int		y;
	int		i;

	i = -1;
	y = -1;
	x = -1;
	nb_char = ft_strlen(size, strs, sep);
	if (!(ret = (char *)malloc(sizeof(char) * nb_char)))
		return (NULL);
	ret[0] = size <= 0 ? '\0' : ret[0];
	while (++y < size)
	{
		while (strs[y][++x])
			ret[++i] = strs[y][x];
		x = -1;
		if (y < size - 1)
			while (sep[++x])
				ret[++i] = sep[x];
		x = -1;
	}
	ret[i + 1] = '\0';
	return (ret);
}
