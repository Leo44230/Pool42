/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 21:12:16 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/23 22:40:22 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_open(char *str, char *ptr)
{
	if (*ptr == 0)
	{
		while (*str != ']')
			str++;
		str++;
	}
	return (str);
}

char	*ft_close(char *str, char *ptr)
{
	if (*ptr != 0)
	{
		while (*str != '[')
			str--;
	}
	return (str);
}

char	*brainfuck(char *str)
{
	char *ptr;
	int i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * 4096);
	if (ptr == 0)
		return (0);
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			(*ptr)++;
		else if (*str == '-')
			(*ptr)--;
		else if (*str == '.')
			ft_putchar(*ptr);
		else if (*str == '[')
		{
			str = ft_open(str, ptr);
		}
		else if (*str == ']')
		{
			str = ft_close(str, ptr);
		}
		str++;
	}
	return (ptr);
}

int main()
{
	brainfuck("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
}
