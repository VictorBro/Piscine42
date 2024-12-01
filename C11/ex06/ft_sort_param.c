#include <unistd.h>

int ft_strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void ft_swap(char **str1, char **str2)
{
	char *tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void ft_write(int argc, char *argv[])
{
	int i;
	char *str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int i;
	int j;

if (argc < 2)
return (0);
i = 0;
while (i < argc - 2)
{
j = 2;
while (j < argc - i)
{
if (ft_strcmp(argv[j], argv[j - 1]) < 0)
{
ft_swap(&argv[j], &argv[j - 1]);
}
j++;
}
i++;
}
ft_write(argc, argv);
return (0);
}
