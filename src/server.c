/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:31:39 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/27 15:31:43 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_size = 0;

char	*print_message(char *message)
{
	if (!message)
		return (NULL);
	ft_printf("INCOMING MESSAGE FROM CLIENT: \n%s\n", message);
	free(message);
	g_size = 0;
	return (NULL);
}

char	*message_mem_allocate(int len)
{
	char	*message;

	message = (char *)malloc(len + 1);
	if (!message)
	{
		write(2, "malloc error", 12);
		return (NULL);
	}
	return (message);
}

void	msg_len_deal(int sig)
{
	static int	len;
	static int	count_bits;

	if (sig == SIGUSR1)
		len = (len << 1) | 1;
	else
		len = len << 1;
	count_bits++;
	if (count_bits == 32)
	{
		g_size = len;
		ft_printf("Message has %d characters, excluding terminator\n", g_size - 1);
		len = 0;
		count_bits = 0;
	}
}

void	message_text_deal(int signal)
{
	static char	*message = NULL;
	static char	c;
	static int	i;
	static int	j;

	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1);
	i++;
	if (i == 8)
	{
		if (message == NULL)
			message = message_mem_allocate(g_size);
		message[j] = c;
		j++;
		i = 0;
		c = 0;
	}
	if (j == g_size)
	{
		j = 0;
		message = print_message(message);
	}
}

int	main(void)
{
	struct sigaction	sa_size;
	struct sigaction	sa_message;

	sa_size.sa_handler = msg_len_deal;
	sigemptyset(&sa_size.sa_mask);
	sa_size.sa_flags = SA_NOCLDWAIT;
	sa_message.sa_handler = message_text_deal;
	sigemptyset(&sa_message.sa_mask);
	sa_message.sa_flags = SA_NOCLDWAIT;
	ft_printf("Please enter the following PID in client: %d\n", getpid());
	while (1)
	{
		if (g_size == 0)
		{
			sigaction(SIGUSR1, &sa_size, NULL);
			sigaction(SIGUSR2, &sa_size, NULL);
		}
		else
		{
			sigaction(SIGUSR1, &sa_message, NULL);
			sigaction(SIGUSR2, &sa_message, NULL);
		}
	}
}
