/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:59:29 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/19 10:23:25 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		i;

	i = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	if (power == 1)
		return (nb);
	while (power > 1)
	{
		i = i * nb;
		power--;
	}
	return (i);
}
