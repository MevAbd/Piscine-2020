/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 09:11:26 by malbrand          #+#    #+#             */
/*   Updated: 2020/10/27 09:11:33 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int			ft_sep(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int			ft_count(char *str, char *charset)
{
	int		i;
	int		nb_word;
	int		here;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		here = ft_sep(str[i], charset);
		if (((ft_sep(str[i - 1], charset) == 0) && here == 1 && i != 0) ||
			(here == 0 && str[i + 1] == '\0'))
			nb_word++;
		i++;
	}
	return (nb_word);
}

int			ft_charset(char *str, char *charset, int i)
{
	int		j;

	j = 0;
	while (charset[j])
	{
		if (charset[j] == str[i])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

int			ft_str(char *str, char *charset, int i)
{
	int	j;

	j = 0;
	while (str[i])
	{
		while (charset[j])
		{
			if (str[i] == charset[j])
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

char		**ft_split(char *str, char *charset)
{
	char	**ret;
	int		x;
	int		y;
	int		i_str;
	int		i_charset;

	x = 0;
	i_str = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * ft_count(str, charset) + 1)))
		return (NULL);
	while (x < (ft_count(str, charset)))
	{
		y = -1;
		i_charset = ft_charset(str, charset, i_str);
		i_str = ft_str(str, charset, i_charset);
		if (!(ret[x] = (char*)malloc(sizeof(char) * (i_str - i_charset) + 1)))
			return (NULL);
		while (i_charset <= i_str)
			ret[x][++y] = str[i_charset++];
		ret[x][y] = '\0';
		x++;
	}
	ret[x] = NULL;
	return (ret);
}
