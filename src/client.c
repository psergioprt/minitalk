#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	while (message[i])
	{
		char	c = message[i];
		while (j < 8)
		{
			if (c & (128 >> j))
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(100);
			j++;
		}
		i++;
	}
	return (0);
}
