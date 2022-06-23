/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:10:45 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/23 18:07:27 by ytoro-mo         ###   ########.fr       */
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
	t_map_tiles	**map_textures;
	t_map_tiles	*line_tmp;

	mlx = mlx_init(ft_map_wth(map), ft_map_hth(map), "SO_LONG", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	map_textures = ft_tiled_map(map);
	printf("VALUE:		%i\n", map_textures[0]->x_pos);
	while (*map_textures)
	{
		line_tmp = *map_textures;
		while (line_tmp)
		{
			mlx_image_to_window(mlx, mlx_texture_to_image(mlx,
					line_tmp->texture), line_tmp->x_pos, line_tmp->y_pos);
			line_tmp = line_tmp->nxt;
		}
		map_textures++;
	}
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}

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

t_map_tiles	**ft_tiled_map(char **map)
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
		map_texture[i] = ft_map_line(map[i], y);
		y += 64;
	}
	map_texture[i] = NULL;
	free(map);
	return (map_texture);
}

t_map_tiles	*ft_map_line(char *line, int y)
{
	int			i;
	t_map_tiles	*map_line;
	t_map_tiles	*map_tmp;
	int			x;

	i = -1;
	x = 0;
	map_line = malloc(sizeof(t_map_tiles *));
	if (!map_line)
		return (NULL);
	map_tmp = map_line;
	while (line[++i])
	{
		map_tmp->texture = mlx_load_png(ft_texture_selector(line[i]));
		map_tmp->x_pos = x;
		map_tmp->y_pos = y;
		x += 64;
		if (line[i + 1])
			map_tmp->nxt = malloc(sizeof(t_map_tiles *));
		else
			map_tmp->nxt = NULL;
		map_tmp = map_tmp->nxt;
	}
	free(line);
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
