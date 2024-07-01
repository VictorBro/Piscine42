#include "cub3d.h"


int valid_move(t_info *info, int keycode)
{
	if (keycode == KEY_LEFT)
	{
		if (info->x - 1 < 0)
			return (FALSE);
		printf("left key pressed\n");
		return (TRUE);
	}
	else if (keycode == KEY_RIGHT)
	{
		if (info->x + SQUARE_SIZE >= SCREEN_WIDTH)
			return (FALSE);
		printf("right key pressed\n");
		return (TRUE);
	}
	else if (keycode == KEY_UP)
	{
		if (info->y - 1 < 0)
			return (FALSE);
		printf("up key pressed\n");
		return (TRUE);
	}
	else if (keycode == KEY_DOWN)
	{
		if (info->y + SQUARE_SIZE >= SCREEN_HEIGHT)
			return (FALSE);
		printf("down key pressed\n");
		return (TRUE);
	}
	return (FALSE);
}

int key_press(int keycode, t_info *info)
{
	int i;
	int j;
	int tmp;

	if (keycode != KEY_UP && keycode != KEY_DOWN && keycode != KEY_RIGHT && keycode != KEY_LEFT &&
		keycode != ARROW_LEFT && keycode != ARROW_RIGHT)
		return (OK);
	tmp = info->angle - 30;
	if (tmp < 0)
		tmp += 360;
	draw_direction(info, tmp, BLACK);
	draw_direction(info, info->angle, BLACK);
	tmp = (info->angle + 30) % 360;
	draw_direction(info, tmp, BLACK);
	ft_draw_tiles(info);
	if (keycode == ARROW_RIGHT)
		info->angle = (info->angle + 1) % 360;
	else if (keycode == ARROW_LEFT) {
		info->angle -= 1;
		if (info->angle < 0)
			info->angle += 360;
	}
	if ((keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_RIGHT || keycode == KEY_LEFT) && valid_move(info, keycode))
	{
		i = 0;
		while (i < SQUARE_SIZE)
		{
			j = 0;
			while (j < SQUARE_SIZE)
			{
				img_pix_put(&info->img, info->x + j, info->y + i, BLACK);
				//info->img.img_addr[(info->y + i) * (info->img.size_line / 4) + info->x + j] = BLACK;
				j++;
			}
			i++;
		}
		if (keycode == KEY_LEFT)
			info->x -= 1;
		else if (keycode == KEY_RIGHT)
			info->x += 1;
		else if (keycode == KEY_UP)
			info->y -= 1;
		else if (keycode == KEY_DOWN)
			info->y += 1;
	}
	tmp = info->angle - 30;
	if (tmp < 0)
		tmp += 360;
	draw_direction(info, tmp, RED);
	draw_direction(info, info->angle, RED);
	tmp = (info->angle + 30) % 360;
	draw_direction(info, tmp, RED);
	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			/* info->img.img_addr[(info->y + i) * (info->img.size_line / 4) + info->x + j] = WHITE; */
			img_pix_put(&info->img, info->x + j, info->y + i , WHITE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img_ptr, 0, 0);
	return (OK);
}

int update_image(t_info *info)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img.img_ptr, 0, 0);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 2 || check_extension(argv[1], ".cub") == FALSE )
	{
		return (ft_error("Wrong file extension, should be .cub file\n\n"));
	}
	init_info(&info);
	if(parse_cub_file(argv[1], &info) == FALSE)
	{
		//free_func
		return (ft_error("Invalide map \n"));
	}


	if (init_mlx_window(&info) == FALSE)
	{
		return (ft_error("Failed to initialize mlx window\n"));
	}
	mlx_key_hook(info.win, key_release, &info);
	mlx_hook(info.win, 17, 0, ft_close, &info);
	mlx_hook(info.win, KEY_PRESS, 1L << 0, key_press, &info);
	//mlx_loop_hook(info.mlx, update_image, &info);
	mlx_loop(info.mlx);
	mlx_destroy_display(info.mlx);
	return (TRUE);
}
