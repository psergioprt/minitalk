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

#include "../../include/minitalk.h"

void	ft_perror_x(const char *s, const char *error_msg, int exit_code)
{
	if (s && *s)
	{
		write (STDERR_FILENO, s, ft_strlen(s));
		write (2, ": ", 2);
	}
	if (error_msg && *error_msg)
		write (2, error_msg, ft_strlen(error_msg));
	write (2, "\n", 1);
	exit (exit_code);
}

void	output_error_usage(const char *program_name)
{
	const char *msg1 = "UsageXXX";
	const char *msg2 = " <PID> <message>\n";

	write (2, msg1, ft_strlen(msg1));
	write (2, program_name, ft_strlen(program_name));
	write (2, msg2, ft_strlen(msg2));
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (128 >> i))
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
		i++;
	}

}

int	main(int argc, char *argv[])
{
	int	i = 0;
	char	*message;

	if (argc != 3)
	{
		output_error_usage(argv[0]);
		return (1);
	}
	pid_t pid = ft_atoi(argv[1]);
	message = argv[2];
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	return (0);
}
