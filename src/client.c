/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:31:30 by pauldos-          #+#    #+#             */
/*   Updated: 2024/07/04 10:44:16 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	send_32bit_len_string(size_t pid, size_t len)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((len >> (31 - i)) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_perror_x("kill", "Failed to send signal", EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_perror_x("kill", "Failed to send signal", EXIT_FAILURE);
		}
		usleep(100);
		i++;
	}
}

static void	send_message(pid_t pid, const char *message, size_t len)
{
	size_t	i;
	int		bit;

	i = 0;
	while (i < len)
	{
		bit = 0;
		while (bit < 8)
		{
			if (message[i] & (128 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_perror_x("kill", "Failed to send signal", 1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_perror_x("kill", "Failed to send signal", EXIT_FAILURE);
			}
			usleep(100);
			bit++;
		}
		i++;
	}
}

static	void	message_send_confirmation(int sig)
{
	if (sig == SIGUSR1)
		write (1, "MESSAGE HAS BEEN SUCCESSFULLY SENT\n", 35);
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	const char			*message;
	size_t				len;
	struct sigaction	sa_message;

	if (argc != 3)
	{
		output_error_usage(argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_perror_x("ft_atoi", "Invalid PID", EXIT_FAILURE);
	message = argv[2];
	sa_message.sa_handler = message_send_confirmation;
	sigemptyset(&sa_message.sa_mask);
	if (sigaction(SIGUSR1, &sa_message, NULL) == -1)
		ft_perror_x("sigaction", "Failed to set up signal handler", 1);
	len = ft_strlen(message) + 1;
	send_32bit_len_string(pid, len);
	send_message(pid, message, len);
	return (0);
}
