#include <stdio.h>
#include <stdlib.h>

int	ft_pow(int base, int exponent)
{
	int	i;
	int	power;

	i = 0;
	power = 1;
	while (i < exponent)
	{
		power = base * power;
		i++;
	}
	return (power);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int	numberToBinary[8];
		int	i;
		int	number;

		i = 7;
		number = atoi(argv[1]);
		while (i >= 0)
		{
			numberToBinary[i] = number % 2;
			number /= 2;
			i--;
		}
		printf("The number you have inserted %d, converted to Binary is: ", atoi(argv[1]));
		i = 0;
		while (i < 8)
		{
			printf("%d", numberToBinary[i]);
			i++;
		}
		int	number2;
		i = 0;
		while (i < 8)
		{
			number2 = number2 * 2 + numberToBinary[i];
			i++;
		}
		printf("\n%d\n", number2);
	}
	else
		printf("Please enter a single argument after program!!!\n");
	return (0);	
}
