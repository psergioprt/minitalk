#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int	asciiCode;
		int	binaryCode[8];
		int	i;

		asciiCode = *argv[1]; 
		i = 7;
		while (i >= 0)
		{
			binaryCode[i] = asciiCode % 2;
			asciiCode /= 2;
			i--;
		}
		i = 0;
		while (i <= 7)
		{
			printf("%d", binaryCode[i]);
			i++;
		}
		printf("\n");	
	}
	else
		printf("Enter a single argument\n");
	return (0);
}
