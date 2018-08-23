/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:26:32 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/22 14:18:50 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list    *top(t_list **begin_list)
{
	t_list  *list;

	list = *begin_list;
	if (list == 0)
		return (0);
	while (list)
	{
		if (list->next == 0)
			return (list);
		list = list->next;
	}
	return (0);
}
/*
int	main()
{
	t_list *list;
	list = 0;

//	push(&list, "bjr");
//	push(&list, "ca");
//	push(&list, "va");
	printf("%s\n", top(&list));
}*/
