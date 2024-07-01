#include "cub3d.h"

int exit_free_util(t_info *info, char *line, char *msg)
{
	(void)info;
	//free_stuff
	//free_line
	if (line)
	{
		free(line);
		line = NULL;
	}
	/*if (info->walls.no_textu)
	{
		if (info->walls.no_textu.img_path)
			free(info->walls.no_textu.img_path);
		if (info->walls.no_textu.img_ptr)
			mlx_destroy_image(info->mlx, info->walls.no_textu.img_ptr);
	}
	if (info->walls.so_textu)
	{
		if (info->walls.so_textu.img_path)
			free(info->walls.so_textu.img_path);
		if (info->walls.so_textu.img_ptr)
			mlx_destroy_image(info->mlx, info->walls.so_textu.img_ptr);
	}
	if (info->walls.ea_textu)
	{
		if (info->walls.ea_textu.img_path)
			free(info->walls.ea_textu.img_path);
		if (info->walls.ea_textu.img_ptr)
			mlx_destroy_image(info->mlx, info->walls.ea_textu.img_ptr);
	}
	if (info->walls.we_textu)
	{
		if (info->walls.we_textu.img_path)
			free(info->walls.we_textu.img_path);
		if (info->walls.we_textu.img_ptr)
			mlx_destroy_image(info->mlx, info->walls.we_textu.img_ptr);
	}*/
	if (msg)
		ft_error(msg);
	else
		ft_error(NULL);
	exit(FALSE);
	return (OK);
}

int count_tabs(char **split_path)
{
	int i;

	i = 0;
	while (split_path[i])
		i++;
	return (i);
}

void free_split(char **split_path)
{
	int i;

	i = 0;
	while (split_path[i])
	{
		free(split_path[i]);
		i++;
	}
	free(split_path);
	split_path = NULL;
}

void parse_path(t_info *info, t_image *textu, char *line)
{
	char *path;
	char **split_path;

	// if (*textu)
	// 	exit_free_util(info, line, "Duplicate texture path\n");
	split_path = ft_split(line, ' ');//to check
	if (count_tabs(split_path) != 1)
	{
		free_split(split_path);
		exit_free_util(info, line, "Texture path error\n");
	}
	path = ft_strtrim(line, " \t\n\v\f\r");
	if (check_extension(path, ".xpm") == FALSE)
	{
		free(path);
		exit_free_util(info, NULL, "Texture path error\n");
	}
	if (!path)
		exit_free_util(info, NULL, "Malloc error\n");

	textu->img_path = path;
	textu->img_ptr = mlx_xpm_file_to_image(info->mlx, path, &textu->width, &textu->height);
	if (textu->img_ptr)
	{
		free(path);
		exit_free_util(info, NULL, "Texture path error\n");
	}
	textu->img_addr = mlx_get_data_addr(textu->img_ptr, &(textu->bpp), &textu->size_line, &textu->endian);

	ft_printf("image width is %d, image height is %d\n", textu->width, textu->height);
}

void parse_color(t_info *info, int *rgb , char *line)
{
	char **split_color;
	char *trim_line;
	int i;
	int j;

	i = 0;
	j = 0;
	trim_line = ft_strtrim(line, " \t\n\v\f\r");
	split_color = ft_split(trim_line, ',');
	if (count_tabs(split_color) != 3)
	{
		free(trim_line);
		free_split(split_color);
		exit_free_util(info, line, "Color error\n");
	}
	while(split_color[i])
	{
		while(split_color[i][j])
		{
			if(ft_isdigit(split_color[i][j]) == FALSE)
			{
				free(trim_line);
				free_split(split_color);
				exit_free_util(info, line, "Color error\n");
			}
			j++;
		}
		i++;
	}
	while (i < 3)
	{
		rgb[i] = ft_atoi(split_color[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free(trim_line);
			free_split(split_color);
			exit_free_util(info, line, "Color error\n");
		}
		i++;
	}
	free_split(split_color);
}

int finish_texture_parse(t_info *info)
{
	if (!info->walls.no_textu.img_addr || !info->walls.so_textu.img_addr || !info->walls.ea_textu.img_addr || !info->walls.we_textu.img_addr)
		return (FALSE);
	return (TRUE);
}

int line_is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int parse_texture_map(t_info *info, char *line)
{
	//need to split first all words
while (!line_is_empty(line) && finish_texture_parse(info) == FALSE)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO\t", 3))
		parse_path(info, &(info->walls.no_textu), line + 3);
	else if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO\t", 3))
		parse_path(info, &(info->walls.so_textu), line + 3);
	else if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA\t", 3))
		parse_path(info, (&info->walls.ea_textu), line + 3);
	else if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE\t", 3))
		parse_path(info, (&info->walls.we_textu), line + 3);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F\t", 2))
		parse_color(info, info->walls.floor, line + 2);
	else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C\t", 2))
		parse_color(info, info->walls.ceiling, line + 2);
}
if (finish_texture_parse(info) == FALSE)
{
	printf("parsing error\n");
	return (FALSE);
}



	/* else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F\t", 2))
		parse_color(info, &info->walls.f_c[0], line + 2);
	else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C\t", 2))
		parse_color(info, &info->walls.f_c[1], line + 2); */
	//else if (parse_map(info, line) == FALSE)//fix this
		//return (FALSE);
	return (TRUE);


}
