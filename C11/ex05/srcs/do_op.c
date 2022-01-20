/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:06:24 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/28 18:08:05 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = -nb;
	}
	else
		nbr = nb;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int		ft_atoi(char *str)
{
	int		i;
	int		neg;
	int		ret;

	ret = 0;
	neg = 1;
	i = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * neg);
}

int		calc(int a, int b, char *op)
{
	if (op[1] == '\0')
	{
		if (op[0] == '-')
			return (a - b);
		if (op[0] == '+')
			return (a + b);
		if (op[0] == '/')
			return (a / b);
		if (op[0] == '%')
			return (a % b);
		if (op[0] == '*')
			return (a * b);
	}
	return (0);
}

int		check_error(int b, char *op)
{
	if (op[0] == '/' && b == 0)
		return (-1);
	if (op[0] == '%' && b == 0)
		return (-2);
	if (op[0] != '-' && op[0] != '+' && op[0] != '/' &&
		op[0] != '%' && op[0] != '*')
		return (-3);
	return (0);
}

int		main(int ac, char **av)
{
	int		a;
	int		b;
	int		check;

	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (ac != 4)
		return (0);
	check = check_error(b, av[2]);
	if (check < 0)
	{
		if (check == -1)
			write(1, "Stop : division by zero\n", 24);
		if (check == -2)
			write(1, "Stop : modulo by zero\n", 22);
		if (check == -3)
			write(1, "0\n", 2);
		return (0);
	}
	ft_putnbr(calc(a, b, av[2]));
	write(1, "\n", 1);
	return (0);
}
