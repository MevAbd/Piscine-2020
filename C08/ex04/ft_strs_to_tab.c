/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:14:56 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/27 11:23:55 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		size;
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	size = ft_strlen(src) + 1;
	if (src == NULL)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*doug;
	int				i;

	i = 0;
	if (!(doug = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	while (i < ac)
	{
		doug[i].size = ft_strlen(av[i]);
		doug[i].str = av[i];
		doug[i].copy = ft_strdup(av[i]);
		if (doug[i].str == 0 || doug[i].copy == 0)
			return (NULL);
		i++;
	}
	doug[i].str = 0;
	return (doug);
}
