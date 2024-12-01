#include <unistd.h>
#include <fcntl.h>

int ft_print_file(char *fname)
{
	int	fd;
	char	ch;
	int	bytes_read;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return(-1);
	while ((bytes_read = read(fd, &ch, 1)) > 0)
	{
		write(1, &ch, 1);
	}
	close(fd);
	if (bytes_read < 0 )
		return (-1);
	return (0);
}

int main(int argc, char *argv[])
{
	char	no_arg[] = "File name missing.\n";
	char	too_many[] = "Too many arguments.\n";
	char	err_read[] = "Cannot read file.\n";

	if (argc == 1)
		write(1, no_arg, sizeof(no_arg) - 1);
	else if (argc > 2)
		write(1, too_many, sizeof(too_many) - 1);
	else if (ft_print_file(argv[1]) < 0)
			write(1, err_read, sizeof(err_read) - 1);
	
	return (0);
}
