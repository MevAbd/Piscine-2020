/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 07:01:00 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/21 08:08:36 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb == 2)
		return (1);
	if (nb < 0 || nb == 1 || nb % 2 == 0)
		return (0);
	while (i < nb && i < 46340)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
