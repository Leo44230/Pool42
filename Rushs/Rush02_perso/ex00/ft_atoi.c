/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:35:43 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/18 04:07:05 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcts.h"

int	display_number(char *str, int i, int signe)
{
	int nb;

	nb = str[i] - 48;
	i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
	{
		nb = 10 * nb + (str[i] - 48);
		i++;
	}
	return (signe * nb);
}

int	ft_atoi(char *str)
{
	int len;
	int i;
	int signe;

	signe = 1;
	i = 0;
	len = ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (i < len)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')
			return (0);
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (0);
			signe = (str[i] == '-') ? (-1) : 1;
		}
		if (str[i] >= '0' && str[i] <= '9')
			return (display_number(str, i, signe));
		i++;
	}
	return (0);
}
