#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void	ft_puterr()
{
	char	*err;

	err = strerror(errno);
	while (*err != '\0')
	{
		write(1, err, 1);
		err++;
	}
	write(1, "\n", 1);
}

void	ft_read(int fd)
{
	char	buffer[30000];
	int		ret_bytes;

	ret_bytes = read(fd, buffer, sizeof(buffer));
	while (ret_bytes > 0)
	{
		write(1, buffer, ret_bytes);
		ret_bytes = read(fd, buffer, sizeof(buffer));
	}
	if (ret_bytes == -1)
		ft_puterr();
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;

	if (argc == 1)
		ft_read(0);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			ft_read(0);
		else
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
				ft_puterr();
			else
			{
				ft_read(fd);
				close(fd);
			}
		}
		i++;
	}
	return (0);
}
