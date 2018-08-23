/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:18:05 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/22 16:20:35 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_list
{
	    struct s_list   *next;
		void            *data;
}					t_list;

t_list				*ft_create_elem(void *data);

t_list	*ft_create_elem(void *data);
void 	push(t_list **begin_list, void *data);
void    *pop(t_list **begin_list);
t_list	*top(t_list **begin_list);

char    **ft_split_whitespaces(char *str);
void	ft_putnbr(int n);
char	*ft_atoi(char *str);

void	ft_add(char *a, char *b);
void	ft_sub(char *a, char *b);
void	ft_mul(char *a, char *b);
void	ft_div(char *a, char *b);
void	ft_mod(char *a, char *b);

#endif
