#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	//unsigned int test = 4000000000;
	//printf("hello this is printf %6i\n", 123);
	ft_printf("[%#x]\n", LONG_MIN);
	printf("[%#x]\n", LONG_MIN);
}
