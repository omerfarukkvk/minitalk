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

int	ft_atoi(char *s)
{
	int	i;

	i = 0;
	while (*s)
		i = (i * 10) + (*s - '0');
	return (i);
}

void	ft_take(pid_t pid, int c)
{
	int				n;
	int				byt;
	unsigned char	ch;

	ch = c;
	byt = 8;
	n = 128;
	while (byt--)
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
	int		pid;
	int		i;
	char	*msg;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		msg = av[2];
		while (msg[i])
		{
			ft_take(pid, msg[i]);
			i++;
		}
	}
	else
	{
		ft_printf("%s", "Wrong!!!");
		return (0);
	}
}
