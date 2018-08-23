/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 23:36:39 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/18 05:27:46 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcts.h"

char	*fst_last_line00(int col, int line, int last)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	str = malloc(sizeof(char) * (col + 2));
	if (str == 0)
		return (0);
	i = col - 2;
	str[j] = 'o';
	j++;
	while (i > 0)
	{
		str[j] = '-';
		j++;
		i--;
	}
	if (col != 1)
	{
		str[j] = 'o';
		j++;
	}
	str[j] = '\n';
	str[j + 1] = 0;
	return (str);
}

char	*other_lines00(int col)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * (col + 2));
	if (str == 0)
		return (0);
	j = 0;
	i = col - 2;
	str[j] = '|';
	j++;
	while (i > 0)
	{
		str[j] = ' ';
		j++;
		i--;
	}
	if (col != 1)
	{
		str[j] = '|';
		j++;
	}
	str[j] = '\n';
	str[j + 1] = 0;
	return (str);
}

char	*colle00(int col, int line)
{
	int		i;
	char	*str;

	if (line == 0 || col == 0)
		return (0);
	if (str == 0)
		return (0);
	i = line - 2;
	str = fst_last_line00(col, line, 0);
	if (str == 0)
		return (0);
	while (i > 0)
	{
		str = ft_concat(str, other_lines00(col));
		i--;
	}
	if (line != 1)
	{
		str = ft_concat(str, fst_last_line00(col, line, 1));
	}
	return (str);
}
