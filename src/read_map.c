/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:10:45 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/24 12:38:08 by ytoro-mo         ###   ########.fr       */
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
	free(line);
	ft_print_map(map);
}

void	ft_print_map(char **map)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map_tiles	***map_textures;
	int			x;
	int			y;

	mlx = mlx_init(ft_map_wth(map), ft_map_hth(map), "SO_LONG", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	map_textures = ft_map_texture((ft_map_wth(map) / 64), (ft_map_hth(map) / 64), map);
	y = 0;
	while (y < ft_map_hth(map))
	{
		x = 0;
		while (x < ft_map_wth(map))
		{
			img = mlx_texture_to_image(mlx, mlx_load_png(LAND_PATH));
			mlx_image_to_window(mlx, img, x, y);
			img = mlx_texture_to_image(mlx, mlx_load_png(map_textures[y / 64][x / 64]->path));
			mlx_image_to_window(mlx, img, x, y);
			x += 64;
		}
		y += 64;
	}
	free(map);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}

t_map_tiles	***ft_map_texture(int size_l, int size_c, char **map)
{
	t_map_tiles	***map_texture;
	int			i;

	map_texture = malloc(sizeof(t_map_tiles **) * size_c);
	if (!map_texture)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < size_c)
	{
		map_texture[i] = ft_map_line(size_l, map[i]);
	}
	return (map_texture);
}

t_map_tiles	**ft_map_line(int size, char *line)
{
	t_map_tiles	*tile;
	t_map_tiles	**map_line;
	int			i;

	i = -1;
	map_line = malloc(sizeof(t_map_tiles *) * size);
	if (!map_line)
		exit(EXIT_FAILURE);
	while (++i < size)
	{
		tile = malloc(sizeof(t_map_tiles));
		if (!tile)
			exit(EXIT_FAILURE);
		tile->path = ft_texture_path(line [i]);
		map_line[i] = tile;
	}
	return (map_line);
}

char	*ft_texture_path(char c)
{
	if (c == '1')
		return (OBSTACLE_PATH);
	else if (c == '0')
		return (LAND_PATH);
	else if (c == 'E')
		return (EXIT_PATH);
	else if (c == 'C')
		return (LAND_BASE_PATH);
	else
		return (LAND_BASE_PATH);
}
