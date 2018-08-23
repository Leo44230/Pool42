/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 04:19:31 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/18 17:34:55 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcts.h"
#include "ft_colle.h"

int	nb_col(char *str)
{
	int i;
	
	i = 0;
	if (str[i] == 0)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int nb_line(char *str)
{
	int i;
	int n;
	
	n = 0;
	i = 0;
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}


void	ft_find_colle(int col, int line, char *str)
{
	int i;
	int num;
	
	num = -1;
	i = 0;
	if (col == 0 | line == 0)
	{
		ft_putstr("aucune\n");
		return ;
	}
	while (i <= 4 && num == -1)
	{
		if (ft_strcmp(g_colletab[i].ft(col, line), str) == 0)
			num = g_colletab[i].num;
		i++;
	}
	if (num == -1)
	{
		ft_putstr("aucune\n");
		return ;
	}
	ft_putstr("[colle-0");
	ft_putnbr(num);
	ft_putstr("] [");
	ft_putnbr(col);
	ft_putstr("] [");
	ft_putnbr(line);
	ft_putstr("]\n");
}
