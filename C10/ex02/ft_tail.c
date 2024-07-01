#include "utils.h"
#include "ft_tail.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_init_tail(t_tail *tail_data, char *size_str)
{
	int	size;

	size = ft_atoi(size_str);
	if (size == 0)
		return (-1);
	tail_data->start = -1;
	tail_data->end = -1;
	tail_data->size = size;
	tail_data->data = (char *)malloc(size * sizeof(char));
	if (!tail_data->data)
	{
		write(1, MEM_ERR, sizeof(MEM_ERR) - 1);
		return (-1);
	}
	return (0);
}

int	ft_read(int fd, t_tail *tail_data)
{
	int		ret_bytes;
	char	ch;

	ret_bytes = read(fd, &ch, 1);
	while (ret_bytes > 0)
	{
		if (tail_data->start == -1)
			tail_data->start = 0;
		else if (tail_data->end - tail_data->start + 1 == tail_data->size)
			tail_data->start++;
		tail_data->end++;
		tail_data->data[tail_data->end % tail_data->size] = ch;
		ret_bytes = read(fd, &ch, 1);
	}
	if (ret_bytes == -1)
	{
		ft_puterr();
		return (-1);
	}
	return (0);
}


void	ft_print_tail(char *fname, t_tail *tail_data)
{
	int	i;

	write(1, "==> ", sizeof("==> ") - 1);
	write(1, fname, ft_strlen(fname));
	write(1, " <==\n", sizeof(" <==\n") - 1);
	i = tail_data->start;
	while (i <= tail_data->end && i != -1)
	{
		write(1, &tail_data->data[i % tail_data->size], 1);
		i++;
	}
}

void	ft_handle_files(int argc, char *argv[], t_tail *tail_data)
{
	int	i;
	int	ret;
	int	fd;

	i = 3;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_puterr();
		else
		{
			tail_data->start = -1;
			tail_data->end = -1;
			ret = ft_read(fd, tail_data);
			close(fd);
			if (ret != -1)
				ft_print_tail(argv[i], tail_data);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		ret;
	t_tail	tail_data;

	if (argc < 3 || ft_strcmp(argv[1], "-c") != 0)
	{
		write(1, USAGE_ERR, sizeof(USAGE_ERR) - 1);
		return (0);
	}
	if (ft_init_tail(&tail_data, argv[2]) == -1)
		return (0);
	if (argc == 3)
	{
		ret = ft_read(0, &tail_data);
		if (ret != -1)
			ft_print_tail("stdin", &tail_data);
	}
	else
	{
		ft_handle_files(argc, argv, &tail_data);
	}
    	free(tail_data.data);
	return (0);
}
