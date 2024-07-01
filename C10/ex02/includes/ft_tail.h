#ifndef FT_TAIL_H
# define FT_TAIL_H
# define USAGE_ERR "Usage: tail -c NUM <files>\n"
# define MEM_ERR "Error: memory allocation failed\n"

typedef struct s_tail
{
	int		start;
	int		end;
	int		size;
	char	*data;
}	t_tail;

int		ft_init_tail(t_tail *tail_data, char *size_str);
int		ft_read(int fd, t_tail *tail_data);
void	ft_print_tail(char *fname, t_tail *tail_data);
void	ft_handle_files(int argc, char *argv[], t_tail *tail_data);
#endif
