#include "cub3d.h"

// Dummy functions to prevent compilation error on MacOS
#ifdef __APPLE__

int	mlx_loop_end(void *mlx_ptr)
{
	(void)mlx_ptr;
	return (1);
}

int	mlx_destroy_display(void *mlx_ptr)
{
	(void)mlx_ptr;
	return (1);
}
#endif

long long	current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

 int	check_extension(char *file_name, char *ext)
{
	int		len;
	char	*start;
	int		ext_len;

	ext_len = ft_strlen(ext);
	len = ft_strlen(file_name);
	start = &file_name[len - ext_len];
	if (ft_strncmp(start, ext, ext_len) == 0)
		return (TRUE);
	return (FALSE);
}

/* int	check_extension(char *file_name)
{
	int		len;
	char	*start;
	int		ext_len;

	ext_len = ft_strlen(FILE_EXT);
	len = ft_strlen(file_name);
	start = &file_name[len - ext_len];
	if (ft_strncmp(start, FILE_EXT, ext_len) == 0)
		return (TRUE);
	return (FALSE);
} */

int	ft_error(const char *msg)
{
	ft_printf("Error\n");
	ft_printf(msg);
	return (FALSE);
}

void init_img(t_image *img)
{
	printf("init_img\n");
	img->img_ptr = NULL;
 	img->img_addr = NULL;
	img->img_path = NULL;
	img->width = -1;
	img->height = -1;
	img->bpp = -1;
	img->size_line = -1;
	img->endian = -1;
	printf("img height is %d\n", img->height);
}

void init_walls(t_walls *walls)
{
	int i;
	i = 0;
	//to do: do i need to init the t_image variables?  is my init ok?

	init_img((walls->no_textu));
/* 	init_img(walls->so_textu);
	init_img(walls->ea_textu);
	init_img(walls->we_textu); */
	while (i < 3)
	{
		walls->floor[i] = -1;
		walls->ceiling[i] = -1;
		i++;
	}
}

void init_info(t_info *info)
{
	info->fd = -1;
	info->mlx = NULL;
	info->win = NULL;
	info->map_h = -1;
	info->map_w = -1;
	info->img.img_ptr = NULL;
	info->img.img_addr = NULL;
	info->x = SCREEN_WIDTH / 2 - SQUARE_SIZE / 2;
	info->y = SCREEN_HEIGHT / 2 - SQUARE_SIZE / 2;
	info->dir = 0;
	info->angle = 0;
	info->walls = ft_calloc(1, sizeof(t_walls));
	init_walls((info->walls));

	//init_walls(info->walls);

}

int	parse_cub_file(char *file_name, t_info *info)
{
	int	fd;
	char *line;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		parse_texture_map(info, line);
		free(line);
		line = get_next_line(fd);
	}
	if (!finish_texture_parse(info))
		return (FALSE);//to verify
	info->fd = fd;
	close(fd);
	return (TRUE);
}

void draw_line(t_info *info, int x1, int y1, int x2, int y2, int color)
{
	int dx, dy, p, x, y;
	dx = x2 - x1;
	dy = y2 - y1;

	x = x1;
	y = y1;

	int incX = (dx > 0) ? 1 : -1;
	int incY = (dy > 0) ? 1 : -1;

	dx = abs(dx);
	dy = abs(dy);

	if (dx > dy) {
		p = 2 * dy - dx;
		while (x != x2)
		{
			img_pix_put(&info->img, x, y, color);
			if (p >= 0) {
				y += incY;
				p -= 2 * dx;
			}
			p += 2 * dy;
			x += incX;
		}
	} else {
		p = 2 * dx - dy;
		while (y != y2)
		{
			img_pix_put(&info->img, x, y, color);
			if (p >= 0) {
				x += incX;
				p -= 2 * dy;
			}
			p += 2 * dx;
			y += incY;
		}
	}
}

void draw_direction(t_info *info, int angle, int color)
{
	int start_x = info->x + SQUARE_SIZE / 2;
	int start_y = info->y + SQUARE_SIZE / 2;
	int end_x, end_y;

	// Calculate end coordinates based on screen boundaries
	if (angle == 0 || angle == 180) {  // Horizontal lines
		end_x = (angle == 0) ? SCREEN_WIDTH : 0;
		end_y = start_y;
	} else if (angle == 90 || angle == 270) {  // Vertical lines
		end_x = start_x;
		end_y = (angle == 90) ? SCREEN_HEIGHT : 0;
	} else {  // Diagonal lines
		double tan_angle = tan(angle * M_PI / 180.0);
		if (angle > 0 && angle < 90) {  // Lines going down right
			end_x = SCREEN_WIDTH;
			end_y = start_y + (int)((SCREEN_WIDTH - start_x) * tan_angle);
		} else if (angle > 90 && angle < 180) {  // Lines going down left
			end_x = 0;
			end_y = start_y + (int)((0 - start_x) * tan_angle);
		} else if (angle > 180 && angle < 270) {  // Lines going left up
			end_x = 0;
			end_y = start_y + (int)((0 - start_x) * tan_angle);
		} else {  // Lines going up right
			end_x = SCREEN_WIDTH;
			end_y = start_y + (int)((SCREEN_WIDTH - start_x) * tan_angle);
		}
		if (end_y < 0 || end_y > SCREEN_HEIGHT) {  // Adjust for out-of-bound y
			printf("end_y = %d\n", end_y);
			if (end_y < 0) {
				end_y = 0;
				end_x = start_x + (int)((0 - start_y) / tan_angle);
			} else {
				end_y = SCREEN_HEIGHT;
				end_x = start_x + (int)((SCREEN_HEIGHT - start_y) / tan_angle);
			}
		}
	}
	printf("angle = %d, end_x=%d, end_y%d\n", angle, end_x, end_y);
	draw_line(info, start_x, start_y, end_x, end_y, color);
}

void ft_draw_tiles(t_info *info)
{
	int x;
	int y;

	y = TILES_SQUARE;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			img_pix_put(&info->img, x, y, WHITE);
			x++;
		}
		y += TILES_SQUARE;
	}

	x = TILES_SQUARE;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			img_pix_put(&info->img, x, y, WHITE);
			y++;
		}
		x += TILES_SQUARE;
	}

}



 void	img_pix_put(t_image *image, int x, int y, int color)
{
    char    *pixel;
    int		i;

    i = image->bpp - 8;
    pixel = image->img_addr + (y * image->size_line + x * (image->bpp / 8));
    while (i >= 0)
    {
        //big endian, MSB is the leftmost bit
        if (image->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        // little endian, LSB is the leftmost bit
        else
            *pixel++ = (color >> (image->bpp - 8 - i)) & 0xFF;
        i -= 8;
    }
}


int	init_mlx_window(t_info *info)
{
	int color = WHITE;
	printf("init_mlx_window\n");
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		return (FALSE);
	info->img.img_ptr = mlx_new_image(info->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (info->img.img_ptr == NULL)
	{
		//todo: free mlx
		free(info->mlx);
		return(ft_error("Failed to create mlx image\n"));
	}
	info->img.img_addr = mlx_get_data_addr(info->img.img_ptr, &info->img.bpp, &info->img.size_line, &info->img.endian);
	int x;
	int y;

	y = info->y;
	while (y < info->y + SQUARE_SIZE)
	{
		x = info->x;
		while (x < info->x + SQUARE_SIZE)
		{
			img_pix_put(&info->img, x, y, color);
			x++;
		}
		y++;
	}
	ft_draw_tiles(info);
	int tmp = info->angle - 30;
	if (tmp < 0)
		tmp += 360;
	draw_direction(info, tmp, RED);
	draw_direction(info, info->angle, RED);
	tmp = (info->angle + 30) % 360;
	draw_direction(info, tmp, RED);
	info->win = mlx_new_window(info->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "minimap");
	if (info->win == NULL)
	{
		ft_error("Failed to create mlx window\n");
		return (FALSE);
	}
	//mlx_put_image_to_window(info->mlx, info->win, info->img.img_ptr, (info->y + (4 * info->x) ), (info->x + 4 * SCREEN_WIDTH * info->y));
	mlx_put_image_to_window(info->mlx, info->win, info->img.img_ptr, 0, 0);
	return (TRUE);
}

void draw_square(t_info *info,  int color)
{
    int start_x;
    int start_y;

    start_y = info->y - SQUARE_SIZE / 2;
    while (start_y < info->y + SQUARE_SIZE / 2)
    {
        start_x = info->x - SQUARE_SIZE / 2;
        while (start_x < info->x + SQUARE_SIZE / 2)
        {
            if (start_x >= 0 && start_x < SCREEN_WIDTH && start_y >= 0 && start_y < SCREEN_HEIGHT)
                info->img.img_addr[start_y * (info->img.size_line / 4) + start_x] = color;
            start_x++;
        }
        start_y++;
    }
}

/* void delete_line(t_info *info, int key_pressed)
{
	int i;
	if (key_pressed == KEY_LEFT)
	{
		i = 0;
		while (i < SQUARE_SIZE)
		{
			info->img.img_addr[(info->y + i - SQUARE_SIZE/2) * (info->img.size_line / 4) + info->x + SQUARE_SIZE] = 0;
			i++;
		}
	}
	else if (key_pressed == KEY_RIGHT)
	{
		for (i = -SQUARE_SIZE / 2; i < SQUARE_SIZE / 2; i++)
		{
			info->img.img_addr[(info->y + i) * (info->img.size_line / 4) + info->x] = 0;
		}
	}
	else if (key_pressed == KEY_UP || key_pressed == KEY_DOWN)
	{
		for (i = -SQUARE_SIZE / 2; i < SQUARE_SIZE / 2; i++)
		{
			if (info->x + i >= 0 && info->x + i < SCREEN_WIDTH && info->y >= 0 && info->y < SCREEN_HEIGHT)
			{
				info->img.img_addr[info->y * (info->img.size_line / 4) + info->x + i] = 0;
			}
		}
	}
} */

int	ft_close(t_info *info)
{
	static int	closed;

	if (!closed)
	{
		closed++;
		if (info->img.img_ptr)
			mlx_destroy_image(info->mlx, info->img.img_ptr);
		mlx_destroy_window(info->mlx, info->win);
		mlx_loop_end(info->mlx);
	}
	if (OS_LINUX == FALSE)
		exit (0);
	return (0);
}

int	key_release(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		ft_close(info);
	return (0);
}
