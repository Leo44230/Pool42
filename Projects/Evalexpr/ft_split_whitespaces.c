/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:54:28 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/19 01:31:17 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int		ft_len_word(char *str)
{
	int n;

	n = 0;
	while (*(str + n) != '\0' && !is_space(*(str + n)))
		n++;
	return (n);
}

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n) != '\0')
		n++;
	return (n);
}

int		countwords(char *str)
{
	int nbwords;
	int i;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (0);
	nbwords = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i])
	{
		if (is_space(str[i]) && is_space(str[i + 1]) == 0 && str[i + 1])
			nbwords++;
		i++;
	}
	return (nbwords + 1);
}

char	**ft_split_whitespaces(char *str)
{
	char	**words;
	int		nbwords;
	int		i;
	int		k;

	nbwords = countwords(str);
	words = (char**)malloc((sizeof(char*)) * (nbwords + 1));
	i = -1;
	k = 0;
	while (++i < nbwords)
	{
		while (*str && is_space(*str))
			str++;
		words[i] = (char *)malloc(sizeof(char) * (ft_len_word(str) + 1));
		k = 0;
		while (*str && !is_space(*str))
		{
			words[i][k] = *str;
			str++;
			k++;
		}
		words[i][k] = 0;
	}
	words[i] = 0;
	return (words);
}
