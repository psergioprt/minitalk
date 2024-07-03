/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:31:30 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/28 12:09:56 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_perror_x(const char *s, const char *error_msg, int exit_code)
{
	if (s && *s)
	{
		write(STDERR_FILENO, s, ft_strlen(s));
		write(2, ": ", 2);
	}
	if (error_msg && *error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit(exit_code);
}

void	output_error_usage(const char *program_name)
{
	const char	*msg1 = "Usage: ";
	const char	*msg2 = " <PID> <message>\n";

	write(2, msg1, ft_strlen(msg1));
	write(2, program_name, ft_strlen(program_name));
	write(2, msg2, ft_strlen(msg2));
}

void	send_32bit_len_string(size_t pid, size_t len)
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

void	send_message(pid_t pid, const char *message, size_t len)
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

int	main(int argc, char *argv[])
{
	pid_t		pid;
	const char	*message;
	size_t		len;

	if (argc != 3)
	{
		output_error_usage(argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_perror_x("ft_atoi", "Invalid PID", EXIT_FAILURE);
	message = argv[2];
	len = ft_strlen(message) + 1;
	send_32bit_len_string(pid, len);
	send_message(pid, message, len);
	return (0);
}
