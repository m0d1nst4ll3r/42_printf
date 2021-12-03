#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	unsigned int test = 4000000000;
	printf("hello this is printf %d %-6i %u %#6x %X %p %c %s\n\n", 78, -800, test, 256, 4564645, &main, 'z', "Zaya");

	ft_printf("hello hello, my ft_printf function works pretty well I'd say\n");
	ft_printf("but does it work with an int ?!? %i YES IT DOES\n", 23);
	ft_printf("omg omg omg so amazing %04-6i %i %i %i %i %i %i\n", 12, 12345, 20000, 2147483647, 2147483648, -2147483648, -1000);
	ft_printf("address test %p\n", &main);
	ft_printf("address test %#x\n", 4564645);
	ft_printf("address test %s\n", "this is a STRING");
}
