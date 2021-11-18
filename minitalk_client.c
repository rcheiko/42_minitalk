/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:35:24 by rcheiko           #+#    #+#             */
/*   Updated: 2021/09/29 14:40:14 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

void	client_2(int j, pid_t pid, char *bin)
{
	if (bin[j] == '1')
	{
		kill(pid, SIGUSR1);
		usleep(500);
	}
	if (bin[j] == '0')
	{
		kill(pid, SIGUSR2);
		usleep(500);
	}
}

void	client(pid_t pid, char *str)
{
	int		i;
	int		j;
	char	*bin;

	i = 0;
	while (str[i])
	{
		j = 0;
		bin = binaire(str[i]);
		while (bin[j])
		{
			client_2(j, pid, bin);
			j++;
		}
		free(bin);
		bin = NULL;
		i++;
	}
}

char	*binaire(char c)
{
	int		bin;
	int		total;
	int		i;
	char	*str;

	bin = (int)c;
	total = 128;
	i = -1;
	str = malloc(9);
	while (++i < 8)
	{
		if (bin / total == 1)
		{
			str[i] = '1';
			bin -= total;
			total /= 2;
		}
		else
		{
			str[i] = '0';
			total /= 2;
		}
	}
	str[i] = '\0';
	return (str);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (is_digit(av[1]) == 0)
			client(ft_atoi(av[1]), av[2]);
	}
	else
		write(1, "ERROR\n", 6);
	return (0);
}
