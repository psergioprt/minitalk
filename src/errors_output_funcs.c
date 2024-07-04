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
