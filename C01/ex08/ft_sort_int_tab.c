/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:05:20 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/14 12:53:54 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		tempo;

	tempo = *a;
	*a = *b;
	*b = tempo;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size - 1 && tab[i + 1] != '\0' && tab[i] != '\0')
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
