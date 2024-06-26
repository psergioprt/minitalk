#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (128 >> i))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				perror("kill");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("kill");
				exit(1);
			}
		}
		usleep(100);
		i++;
	}

}

int	main(int argc, char *argv[])
{
	int	i = 0;
	int	j = 0;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}

	pid_t pid = atoi(argv[1]);
	char	*message = argv[2];
	char	c;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	return (0);
}
