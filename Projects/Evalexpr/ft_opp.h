/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:52:03 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/19 04:16:07 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPP_H
# define FT_OPP_H

typedef struct  s_opp
{
	char    *opp;
	void    (*ft)(char*, char*);
	int		prio;
}               t_opp;

t_opp g_opptab[] =
{
	{"+", &ft_add, 1},
	{"-", &ft_sub, 1},
	{"*", &ft_mul, 2},
	{"/", &ft_div, 2},
	{"%", &ft_mod, 2}
};
#endif
