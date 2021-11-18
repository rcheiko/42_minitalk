/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:18:15 by rcheiko           #+#    #+#             */
/*   Updated: 2021/09/29 14:32:19 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		is_digit(char *str);
int		ft_is_digit(int c);
int		ft_atoi(const char *str);

//client
char	*binaire(char c);
void	client(pid_t pid, char *str);
void	client_2(int j, pid_t pid, char *bin);

#endif
