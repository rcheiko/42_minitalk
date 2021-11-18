/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:24:52 by rcheiko           #+#    #+#             */
/*   Updated: 2021/09/29 14:48:35 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

char	*g_bin;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	bin_to_c(char *str)
{
	int		i;
	int		total;
	int		bin;
	char	c;

	i = 0;
	total = 0;
	bin = 128;
	while (str[i])
	{
		if (str[i] == '1')
			total += bin;
		bin /= 2;
		i++;
	}
	c = (char)total;
	return (c);
}

void	server(int sig)
{
	char	c;
	int		i;

	i = ft_strlen(g_bin);
	if (ft_strlen(g_bin) == 7)
	{
		if (sig == SIGUSR1)
			g_bin[i] = '1';
		if (sig == SIGUSR2)
			g_bin[i] = '0';
		g_bin[i + 1] = '\0';
		c = bin_to_c(g_bin);
		write(1, &c, 1);
		free(g_bin);
		g_bin = NULL;
		g_bin = malloc(9);
		g_bin[0] = '\0';
	}
	else if (sig == SIGUSR1)
		g_bin[i] = '1';
	else if (sig == SIGUSR2)
		g_bin[i] = '0';
	g_bin[i + 1] = '\0';
}

int	main(void)
{
	pid_t	pid;
	char	*str;

	pid = getpid();
	write(1, "PID : ", 6);
	str = ft_itoa(pid);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	g_bin = malloc(9);
	signal(SIGUSR1, server);
	signal(SIGUSR2, server);
	while (1)
		pause();
	return (0);
}
