/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 23:36:39 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/18 05:47:32 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fcts.h"

void	fst_last_line(int col, int last)
{
	int		i;

	i = col - 2;
	if (last == 1)
		ft_putchar('\\');
	else
		ft_putchar('/');
	while (i > 0)
	{
		ft_putchar('*');
		i--;
	}
	if (col != 1)
	{
		if (last == 1)
			ft_putchar('/');
		else
			ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	other_lines(int col)
{
	int		i;

	i = col - 2;
	ft_putchar('*');
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	if (col != 1)
	{
		ft_putchar('*');
	}
	ft_putchar('\n');
}

void	colle01_output(int col, int line)
{
	int		i;

	if (line == 0 || col == 0)
		return ;
	i = line - 2;
	fst_last_line(col, 0);
	while (i > 0)
	{
		other_lines(col);
		i--;
	}
	if (line != 1)
	{
		fst_last_line(col, 1);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		colle01_output(ft_atoi(argv[1]), ft_atoi(argv[2]));
}
