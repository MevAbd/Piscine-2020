/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:06:20 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/14 12:54:20 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		tempo;

	i = 0;
	while (i < size - 1)
	{
		tempo = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = tempo;
		i++;
		size--;
	}
}
