/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:10:45 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/24 11:11:03 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(int fd)
{
	char	**map;
	char	*line;
	int		i;

	i = -1;
	line = get_next_line_c(fd);
	while (line[ft_strlen(line) - 1] == '\n')
		line = ft_strjoin(line, get_next_line_c(fd));
	map = ft_split(line, '\n');
	//free(line);
	ft_print_map(map);
}

void	ft_print_map(char **map)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	//t_map_tiles	**map_textures;
	int 		x;
	int			y;

	mlx = mlx_init(ft_map_wth(map), ft_map_hth(map), "SO_LONG", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	//map_textures = ft_tiled_map(map);
	//printf("VALUE:		%i\n", x_pos);
	y = 0;
	while (y < ft_map_hth(map))
	{
		x = 0;
		while (x < ft_map_wth(map))
		{
			if (y != 0)
			{
				img = mlx_texture_to_image(mlx, mlx_load_png(LAND_PATH));
				mlx_image_to_window(mlx, img, x, y);
			}
			else
			{
				img = mlx_texture_to_image(mlx, mlx_load_png(OBSTACLE_PATH));
				mlx_image_to_window(mlx, img, x, y);
			}
				x += 64;
		}
		y += 64;
	}
	
/* 	i = -1;
	while (++i < (ft_map_hth(map) / 64))
	{
		//line_tmp = map_textures[i];
		j = -1;
		while (++j < (ft_map_wth(map) / 64))
		{
			printf("VALUE:		%s\n", map_textures[i]->path);
			img = mlx_texture_to_image(mlx, mlx_load_png(map_textures[i]->path));
			mlx_image_to_window(mlx, img, map_textures[i]->x_pos, map_textures[i]->y_pos);
			map_textures[i] = map_textures[i]->nxt;
		}
	} */
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
	//free(map);

/* 	while (x < 1024)
	{
		y = 0;
		while (y < 768)
		{
			img = mlx_texture_to_image(mlx, mlx_load_png(LAND_PATH));
			mlx_image_to_window(mlx, img, x, y);
			y += 64;
		}
		x += 64;
	} */

/* t_map_tiles	**ft_tiled_map(char **map)
{
	t_map_tiles	**map_texture;
	int			i;
	int			y;

	i = 0;
	y = 0;
	while (map[i])
		i++;
	map_texture = malloc(sizeof(t_map_tiles *) * i);
	if (!map_texture)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		map_texture[i] = ft_map_line(map[i], y, (ft_map_wth(map) / 64));
		y += 64;
	}
	map_texture[i] = NULL;
	return (map_texture);
}

t_map_tiles	*ft_map_line(char *line, int y, int size)
{
	int			i;
	t_map_tiles	*map_line;
	int			x;

	i = -1;
	x = 0;
	map_line = malloc(sizeof(t_map_tiles) * size);
	if (!map_line)
		return (NULL);
	while (line[++i])
	{
		map_line[i].path = ft_texture_selector(line[i]);
		map_line[i].x_pos = x;
		map_line[i].y_pos = y;
		x += 64;
	} */
	//map_line[i] = 0;
/* 	free(line);
	return (map_line);
}

char	*ft_texture_selector(char c)
{
	if (c == '0')
		return (LAND_PATH);
	else if (c == '1')
		return (OBSTACLE_PATH);
	else if (c == 'C')
		return (LAND_PATH);
	else if (c == 'E')
		return (EXIT_PATH);
	else
		return (LAND_PATH);
}
 */