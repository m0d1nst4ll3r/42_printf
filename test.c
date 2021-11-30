#include "ft_printf.h"

#include <stdio.h>

void	tt_test()
{
	int	i;
	unsigned int test = -1;
	unsigned int	test2 = 5000000000;
	int	test3 = -678;
	void	*p = &p;

	i = ft_printf("€hello 123 $$$ %%   [%s] [%c] [%i] [%d] [%u] [%p] [%x] [%X]  \n", "yo!", 'a', test3, test3, test, p, test2, test2);
	ft_printf("%d\n", i);
	i = printf("€hello 123 $$$ %%   [%s] [%c] [%i] [%d] [%u] [%p] [%x] [%X]  \n", "yo!", 'a', test3, test3, test, p, test2, test2);
	printf("%d\n", i);
}

int	main()
{
	printf("[%.6i]\n", -14542);
	printf("[%.2s]\n", "hello");
	printf("[%.2i]\n", 8546);
	printf("[% -6i]\n", -14542);
}
