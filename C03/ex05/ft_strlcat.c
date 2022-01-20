/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:47:34 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/18 15:37:37 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclen;
	unsigned int	destlen;

	i = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (size <= destlen)
		srclen = srclen + size;
	else
		srclen = srclen + destlen;
	if (size > destlen)
	{
		while (src[i] && (destlen + 1) < size)
		{
			dest[destlen] = src[i];
			i++;
			destlen++;
		}
	}
	dest[destlen] == '\0';
	return (srclen);
}
