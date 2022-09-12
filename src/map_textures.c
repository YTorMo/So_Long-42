/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:44:36 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/12 13:26:17 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_tiles	***ft_map_texture(int size_l, int size_c, char **map)
{
	t_map_tiles	***map_texture;
	int			i;

	map_texture = malloc((sizeof(t_map_tiles **) * size_c) + 1);
	if (!map_texture)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < size_c)
	{
		map_texture[i] = ft_map_line(size_l, map[i], (i * 64));
	}
	map_texture[i] = NULL;
	return (map_texture);
}

t_map_tiles	**ft_map_line(int size, char *line, int y)
{
	t_map_tiles	*tile;
	t_map_tiles	**map_line;
	int			i;

	i = -1;
	map_line = malloc((sizeof(t_map_tiles *) * size) + 1);
	if (!map_line)
		exit(EXIT_FAILURE);
	while (++i < size)
	{
		tile = malloc(sizeof(t_map_tiles));
		if (!tile)
			exit(EXIT_FAILURE);
		tile->path = ft_texture_path(line [i]);
		tile->y_pos = y;
		tile->x_pos = i * 64;
		map_line[i] = tile;
	}
	map_line[i] = NULL;
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
		return (COLLEC_PATH);
	else if (c == 'N')
		return (ENEMY_PATH);
	else
		return (PJR_PATH);
}
