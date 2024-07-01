#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}
/*
int main(void)
{
	int x = 5;
	t_list *tal;
	tal = ft_create_elem(&x);
	printf("%d, %p\n", *(int *)tal->data, tal->next);
	free(tal);
}*/
