/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:20:21 by okavak            #+#    #+#             */
/*   Updated: 2022/07/28 14:56:55 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_success(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\x1b[32mProcess Successful\x1b[0m  \n");
}

int	ft_atoi(char *s)
{
	int	i;

	i = 0;
	while (*s)
		i = (i * 10) + (*s++ - '0');
	return (i);
}

void	ft_take(pid_t pid, int c)
{
	int				n;
	int				bit;
	unsigned char	ch;

	ch = c;
	bit = 8;
	n = 128;
	while (bit--)
	{
		if (ch / n)
		{
			ch -= n;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(150);
		n /= 2;
	}
}

int	main(int ac, char **av)
{
	int		byt;
	int		pid;
	int		i;
	char	*msg;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		msg = av[2];
		signal(SIGUSR1, ft_success);
		while (msg[i])
		{
			ft_take(pid, msg[i]);
			i++;
		}
	}
	else
		return (ft_printf("\x1b[31mWrong!\x1b[0m  \n"));
	byt = 8;
	while (byt--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}
