/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:17:13 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/28 16:54:50 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_growing(int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_decrease(int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		growing;
	int		decrease;

	growing = ft_growing(tab, length, f);
	decrease = ft_decrease(tab, length, f);
	if (growing + decrease == 0)
		return (0);
	return (1);
}
