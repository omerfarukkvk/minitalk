/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:20:32 by okavak            #+#    #+#             */
/*   Updated: 2022/07/27 13:20:37 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_bit(int x)
{
	static int	bit = 7;
	static int	set = 0;

	set += x << bit;
	if (bit == 0)
	{
		write(1, &set, 1);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void	sgl_catch(int x)
{
	if (x == SIGUSR1)
		set_bit(1);
	else if (x == SIGUSR2)
		set_bit(0);
}

int	main(void)
{
	ft_printf("PID: %u\n", getpid());
	signal(SIGUSR1, sgl_catch);
	signal(SIGUSR2, sgl_catch);
	while (1)
		pause();
}
