#include <stdio.h>
#include <unistd.h>

void	printBits(unsigned char c)
{
	int	i;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
	write(1, "\n", 1);
}
int	reverseBits(unsigned char c)
{
	int	i;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = bit * 2 + (c % 2);
		c = c / 2;
		i--;
		//write (1, &bit, 1);
	}
	return (bit);
	//write (1, "\n", 1);
}

int	main(void)
{
	char	c;
	char	converted;
	
	c = 'c';
	printf("%c\n", c);
	printf("Now in binary mode\n");
	printBits(c);
	converted = reverseBits(c);
	printf("Now reversing to bits\n");
	printf("%c", reverseBits(converted));
	return (0);

}
