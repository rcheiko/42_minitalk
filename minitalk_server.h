/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:18:15 by rcheiko           #+#    #+#             */
/*   Updated: 2021/09/29 14:48:54 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

extern char	*g_bin;

char		bin_to_c(char *str);
int			ft_strlen(char *str);

//itoa
char		*ft_itoa(int n);

//server
void		server(int sig);

#endif
