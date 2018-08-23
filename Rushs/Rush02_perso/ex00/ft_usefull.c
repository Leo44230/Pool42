/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 23:33:00 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/18 14:40:04 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcts.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (*str == 0)
		return (0);
	else
	{
		str++;
		return (1 + ft_strlen(str));
	}
}

char	*ft_concat(char *str1, char *str2)
{
	char	*str;
	int		i;

	i = 0;
	if (str == 0)
		return (0);
	if (str1 == 0 && str2)
		return (str2);
	if (str2 == 0 && str1)
		return (str1);
	if (str1 == 0 && str2 == 0)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	while (*str1)
	{
		str[i++] = *str1;
		str1++;
	}
	while (*str2)
	{
		str[i++] = *str2;
		str2++;
	}
	str[i] = 0;
	return (str);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0 && s2[i] == 0)
			return (0);
		i++;
	}
	if (s1[i] == 0 && s2[i] == 0)
		return (0);
	else if (s2[i] == 0)
		return (s1[i]);
	else if (s1[i] == 0)
		return (-s2[i]);
	else
		return (s1[i] - s2[i]);
}


