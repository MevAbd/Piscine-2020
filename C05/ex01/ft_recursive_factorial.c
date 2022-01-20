/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:59:07 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/18 10:59:11 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int		i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb > 1)
		return (nb * ft_recursive_factorial(nb - 1));
	return (1);
}
