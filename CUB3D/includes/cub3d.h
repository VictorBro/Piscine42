#ifndef CU3D_H
# define CU3D_H

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800
#define SQUARE_SIZE 8
#define TILES_SQUARE 50
#define BLACK	0x000000
#define WHITE	0xFFFFFF
#define RED		0xFF0000
#define TRUE 1
#define FALSE 0
#define KEY_PRESS 2
# define FILE_EXT ".cub"

# ifdef __linux__
#  define OS_LINUX		TRUE
#  define KEY_LEFT	 	97
#  define KEY_RIGHT		100
#  define KEY_DOWN		115
#  define KEY_UP		119
#  define ARROW_LEFT	65361
#  define ARROW_RIGHT	65363
#  define ARROW_DOWN	65364
#  define ARROW_UP		65362
#  define KEY_ESC		65307
# elif __APPLE__
#  define OS_LINUX		FALSE
#  define KEY_LEFT		0
#  define KEY_RIGHT		2
#  define KEY_DOWN		1
#  define KEY_UP		13
#  define KEY_ESC		53
#  define ARROW_LEFT	123
#  define ARROW_RIGHT	124
#  define ARROW_DOWN	125
#  define ARROW_UP		126
# endif
# include <sys/time.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include <mlx.h>

enum {
	OK,
	MLX_ERROR,
	IMAGE_ERROR,
	ARG_ERROR,
	MAP_ERROR,
	ALLOC_ERROR,
};

typedef struct s_coord {
	int	row;
	int	col;
}				t_coord;

typedef struct s_image {

	char 	*img_path;
	int 	width;
	int 	height;
	int 	bpp;
	int 	size_line;
	int 	endian;
	void	*img_ptr;
	char 	*img_addr;
}	t_image;

typedef enum s_directions{
	NO = 0,
	SO,
	EA,
	WE,
} t_directions;


typedef struct s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct s_walls
{
	t_image			no_textu;
	t_image			so_textu;
	t_image			ea_textu;
	t_image			we_textu;
	int 			floor[3];
	int 			ceiling[3];
}				t_walls;


/* typedef struct s_config
{
	//struct s_image	*img_map;
	//struct s_image	*img_game;
	int				floor;
	int				ceiling;
	int				width;
	int				height;
	char			**map;
	t_walls			walls;
}		t_config; */

typedef struct	s_info
{
	int		fd;
	void	*mlx;
	void	*win;
	int		map_h;
	int		map_w;
	int		x;
	int		y;
	int		dir;
	t_walls walls;
	t_image	img;
	int		angle;
}				t_info;

int		check_extension(char *file_name, char *ext);
int		ft_error(const char *msg);
void	init_info(t_info *info);
int		parse_cub_file(char *file_name, t_info *info);
int		init_mlx_window(t_info *info);
int		ft_close(t_info *info);
int		key_release(int keycode, t_info *info);
int		key_press(int keycode, t_info *info);
int		valid_move(t_info *info, int keycode);
void	draw_square(t_info *info,  int color);
void	delete_line(t_info *info, int key_pressed);
// void	draw_direction(t_info *info, int dir, int color);
void	draw_direction(t_info *info, int angle, int color);
void	ft_draw_tiles(t_info *info);
int		free_util(t_info *info, char *line, char *msg);
int		parse_texture_map(t_info *info, char *line);
void	img_pix_put(t_image *image, int x, int y, int color);
int finish_texture_parse(t_info *info);
# ifdef __APPLE__

int			mlx_loop_end(void *mlx_ptr);
int			mlx_destroy_display(void *mlx_ptr);
# endif

#endif
