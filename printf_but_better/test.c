#include <stdio.h>
#include <stdlib.h>

typedef struct s_test
{
	struct s_test	*next;
}					t_test;

void	test_add(t_test **test, t_test *add)
{
	add->next = *test;
	*test = add;
}

int	main()
{
	t_test	*elem1;
	t_test	*elem2;
	t_test	*elem3;
	t_test	*elem4;

	elem1 = malloc(sizeof(t_test));
	elem2 = malloc(sizeof(t_test));
	elem3 = malloc(sizeof(t_test));
	elem4 = malloc(sizeof(t_test));

	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = NULL;

	printf("elem4:       %p\n", elem4);
	printf("elem3->next: %p\n", elem3->next);
	test_add(&(elem3->next), elem4);
	printf("elem3->next: %p\n", elem3->next);
}
