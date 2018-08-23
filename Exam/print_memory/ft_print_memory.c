/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 20:35:56 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/23 16:01:56 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	char point = '.';
	if (c < 32 || c == 127)
		write(1, &point, 1);
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

void	int_to_hexa(int n, int all)
{
	char	tab[9];
	int		i;

	i = 0;
	while (n > 0)
	{
		tab[i] = (n % 16 < 10) ? n % 16 + + 48 : 'a' + n % 16 % 10;
		n = n / 16;
		i++;
	}
	if (all == 1)
	{
		while (i < 8)
		{
			tab[i] = '0';
			i++;
		}
	}
	else if (all == 0 && i == 1)
		tab[i++] = 0;
	tab[i] = 0;
	i--;
	while (i >= 0)
	{
		ft_putchar(tab[i]);
		i--;
	}
	if (all)
		ft_putstr(": ");
}

void	print_hexa(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(*str && i < 32)
	{
		int_to_hexa(*str, 0);
		str++;
		if (*str)
		{
			int_to_hexa(*str, 0);
			str++;
			i = i + 2;
		}
		i = i + 2;
		if (i != 32)
			ft_putchar(' ');
	}
	while (i < 32)
	{
		j = 1;
		ft_putchar(' ');
		i++;
	}
	if (j)
		ft_putstr("  ");
	ft_putchar(' ');
}



void *ft_print_memory(void *addr, unsigned int size)
{
	int i;
	int j;
	char *str;
	
	str = (char *)addr;
	i = 0;
	while (i < size && *str)
	{
		j = 0;
		int_to_hexa(i, 1);
		print_hexa(addr);
		ft_putchar(' ');
		while (j < 16 && *str)
		{
			ft_putchar(*str);
			j++;
			str++;
		}
		ft_putchar('\n');
		addr = addr + 16;
		i = i + 16;
	}
	return (addr);
}

int main()
{

	ft_print_memory("Salut les aminches c'est cool show men on fait de truc ter", 80);
	return (0);
}



















