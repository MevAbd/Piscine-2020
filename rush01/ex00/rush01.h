/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youerdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:15:18 by youerdan          #+#    #+#             */
/*   Updated: 2020/10/25 19:06:08 by mdabouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

void	check_four(int tab[6][6]);
void	all_zero(int tab[6][6]);
void	first_value(char *str, int tab[6][6]);
void	ft_print(int tab[6][6]);
int		ft_error(char *s, int ac);
int		is_line_ok(int tab[6][6], int col);
int		is_col_ok(int tab[6][6], int line);
int		check(int tab[6][6]);
int		solvi(int tab[6][6], int n, int *sol);

#endif
