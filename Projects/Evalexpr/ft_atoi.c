/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:35:43 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/19 04:16:02 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n) != '\0')
		n++;
	return (n);
}

char *display_number(char *str, int i, int signe)
{
	char *str2;
	int j;

	j = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str)+2));
	if (signe == -1)
	{
		str2[j] = '-';
		j++;
	}
	while (((str[i] >= '0' && str[i] <= '9') || str[i] == '-')  && str[i] != 0)
	{
		str2[j] = str[i];
		j++;
		i++;
	}
	str2[j] = 0;
	return (str2);
}

char *ft_atoi(char *str)
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
