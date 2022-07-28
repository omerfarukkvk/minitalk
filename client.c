/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:20:21 by okavak            #+#    #+#             */
/*   Updated: 2022/07/27 13:20:23 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
