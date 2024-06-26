#include <stdio.h>

int	main (void)
{
	int	number;
	int	convertBits[8];
	int	i;
	int	temp;

	number = 51;
	temp = number;
	i = 7;
	while (i >= 0)
	{
		convertBits[i] = number % 2;
		number /= 2;
		i--;
	}
	printf("Number %d, converted to bits is: ", temp);
	i = 0;
	while (i < 8)
	{
		printf("%d", convertBits[i]);
		i++;
	}
	return (0);
}
