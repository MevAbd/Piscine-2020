/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youerdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:29:54 by youerdan          #+#    #+#             */
/*   Updated: 2020/10/25 18:30:10 by youerdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_error(char *s, int ac)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (ac != 2)
		ret = 1;
	else
	{
		if (ft_strlen(s) != 31)
			ret = 2;
		while (s[i] != '\0')
		{
			if (i % 2 == 0 && (s[i] < '1' || s[i] > '4'))
				ret = 4;
			if (i % 2 != 0 && s[i] != ' ')
				ret = 5;
			i++;
		}
	}
	if (ret != 0)
		write(1, "Error\n", 6);
	return (ret);
}
