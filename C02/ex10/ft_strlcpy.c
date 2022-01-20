/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:26:57 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/15 17:41:50 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*src != '\0' && i < size + 1)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	while (*src != '\0')
	{
		src++;
		i++;
	}
	*dest = '\0';
	return (i);
}
