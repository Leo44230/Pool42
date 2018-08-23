/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 00:25:25 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/22 16:19:57 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_opp.h"

int		is_braq(char *str)
{
	if (str[0] == '(')
		return (1);
	if (str[0] == ')')
		return (2);
	return (0);
}

int		is_num(char *str)
{
	if (str == 0)
		return (0);
	if (str[0] >= '0' && str[0] <= '9')
		return (1);
	if (str[0] == '-' && str[1] >= '0' && str[1] <= '9')
		return (1);
	return (0);
}

int		is_opp(char *str)
{
	if (str[0] == '+')
		return (0);
	else if (str[0] == '-')
		return (1);
	else if (str[0] == '*')
		return (2);
	else if (str[0] == '/')
		return (3);
	else if (str[0] == '%')
		return (4);
	return (-1);
}

char	*char_str(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

int		opp_sup(char *opp1, t_list *stack)
{
	if (stack == 0)
		return (1);
	if (g_opptab[is_opp(opp1)].prio > g_opptab[is_opp(stack->data)].prio)
		return (1);
	return (0);
}

int		braq(t_list *stack)
{
	if (stack == 0)
		return (0);
	return (is_braq(stack->data));
}

t_list	*output(char *str)
{
	t_list	*output;
	t_list	*stack;
	char	*elem;
	
	output = 0;
	stack = 0;	
	while (*str)
	{
		if (is_num(str))
			push(&output, ft_atoi(str));
		else if (is_opp(str) != -1)
		{
			while (!opp_sup(str, stack) && (!braq((stack))))
				push(&output, pop(&stack));
			push(&stack, char_str(*str));
		}
		else if (is_braq(str) == 1)
			push(&stack, char_str(*str));
		else if (is_braq(str) == 2)
		{
			while (braq(top(&stack)) != 1 && stack)
				push(&output, pop(&stack));
			pop(&stack);
		}

		if (is_num(str))
		{
			str++;
			while (is_num(str))
				str++;
		}
		else
			str++;
	}
	while (stack)
	{
	if (!braq(top(&stack)))
		push(&output, pop(&stack));
	}
	return (output);
}

int main(int argc, char **argv)
{
	t_list	*out;

	out = 0;
	if (argc == 2)
	{
		out = output(argv[1]);

		while (out)
		{
			printf("%s\n", out->data);
			out = out->next;
		}
	}
}
