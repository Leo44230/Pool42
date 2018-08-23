/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 22:22:10 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/18 23:25:34 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	auxpos(int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		auxpos((n - (n % 10)) / 10);
		ft_putchar((n % 10) + 48);
	}
}

void	auxneg(int n)
{
	if (n > (-10))
	{
		ft_putchar(-n + 48);
	}
	else
	{
		auxneg((n + (10 - n % 10) % 10) / 10);
		ft_putchar((10 - (n % 10)) % 10 + 48);
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar(45);
		auxneg(n);
	}
	else
	{
		auxpos(n);
	}
}
