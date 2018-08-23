/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:41:40 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/22 16:59:34 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*pop(t_list **begin_list)
{
	t_list	*list;
	t_list	*next;
	void	*tmp;

	list = *begin_list;
	tmp = 0;
	if (list == 0)
		return (0);
	next = list->next;
	if (next == 0)
	{
		*begin_list = 0;
		return (list->data);
	}
	while (next)
	{
		tmp = (next->next == 0) ? next->data : tmp;
		list->next = (next->next == 0) ? 0 : list->next;
		if (next->next == 0)
			return (next);
		list = list->next;
		next = next->next;
	}
	return (0);
}

