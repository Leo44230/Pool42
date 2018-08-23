/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 23:54:44 by lgillett          #+#    #+#             */
/*   Updated: 2018/08/18 17:32:01 by lgillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCTS_H
# define FCTS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c);
char	*ft_concat(char *str1, char *str2);
int		ft_strlen(char *str);
void	ft_putstr(char *str);	
int		ft_atoi(char *str);
int     ft_strcmp(char *s1, char *s2);
void    ft_putnbr(int n);

char    *colle00(int col, int line);
char    *colle01(int col, int line);
char    *colle02(int col, int line);
char    *colle03(int col, int line);
char    *colle04(int col, int line);

#endif
