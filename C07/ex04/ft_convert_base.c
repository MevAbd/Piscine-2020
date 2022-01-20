/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:05:24 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/27 07:06:00 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *s);

int		check_base(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_error(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (str[i] == 43 || str[i] == 45
				|| (str[i] >= 9 && str[i] <= 13)
				|| str[i] == 32)
			return (1);
		while (str[j])
		{
			if (str[j] == str[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int less;
	int nb;

	i = 0;
	less = 1;
	nb = 0;
	if (ft_strlen(base) <= 1 || ft_error(base) == 1)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			less *= -1;
		i++;
	}
	while (check_base(str[i], base) != -1 && str[i])
	{
		nb = nb * ft_strlen(base) + check_base(str[i], base);
		i++;
	}
	return (nb * less);
}

char	*ft_itoi(char *base_to, char *tab, int nb_base10, int compt)
{
	unsigned int	tmp;
	int				i;
	int				j;
	unsigned int	doug;

	i = 0;
	j = 0;
	if (nb_base10 < 0)
	{
		tab[0] = '-';
		doug = -nb_base10;
		++compt;
		j = 1;
	}
	else
		doug = nb_base10;
	tab[compt] = '\0';
	while (compt > j)
	{
		tmp = doug;
		doug /= ft_strlen(base_to);
		tab[--compt] = base_to[tmp % ft_strlen(base_to)];
		i++;
	}
	return (tab);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		nb_2;
	int		compt;
	char	*tab;
	int		j;

	j = 1;
	compt = 0;
	if (ft_error(base_from) == 1 || ft_error(base_to) == 1)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	if (nb < 0)
		j = 2;
	nb_2 = nb;
	if (nb == 0)
		compt = 1;
	while (nb_2 != 0)
	{
		nb_2 /= ft_strlen(base_to);
		compt++;
	}
	if (!(tab = (char *)malloc(sizeof(char) * compt + j)))
		return (NULL);
	tab = ft_itoi(base_to, tab, nb, compt);
	return (tab);
}
