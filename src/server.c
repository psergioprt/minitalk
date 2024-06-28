/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:31:39 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/28 10:42:58 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static char c = 0;
	static int bit_count = 0;

	if (signal == SIGUSR1)
	{
		c |= (128 >> bit_count);
	}
	bit_count++;
	if (bit_count == 8)
	{
		write (1, &c, 1);
		c = 0;
		bit_count = 0;
	}
}

int main (void)
{
	struct	sigaction sa;
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
