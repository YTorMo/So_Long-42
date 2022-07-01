/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yago_42 <Yago_42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:18 by Yago_42           #+#    #+#             */
/*   Updated: 2022/07/01 19:24:11 by Yago_42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_game_init(int fd)
{
	t_map_data	*map;

	map = ft_map_data(fd);
	map->mlx = mlx_init(map->map_wth, map->map_hth + 20, "SO_LONG", true);
	if (!map->mlx)
		exit(EXIT_FAILURE);
	ft_img_filler(map);
	ft_back_printer(map);
	ft_img_printer(map);
	map->txt = mlx_put_string(map->mlx, "MOVES:	0", 0, map->map_hth);
	map->txt_c = mlx_put_string(map->mlx, ft_strjoin("ITEMS:	", ft_itoa(map->collec)), 110, map->map_hth);
	map->mov = 0;
	mlx_key_hook(map->mlx, &ft_keyhook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}

// NO olvidar mlx_delete_image(mlx, img);

void	ft_img_filler(t_map_data *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_textures[++i])
	{
		j = -1;
		while (map->map_textures[i][++j])
		{
			map->map_textures[i][j]->img = mlx_texture_to_image(map->mlx, mlx_load_png(map->map_textures[i][j]->path));
		}
	}
}

void	ft_img_printer(t_map_data *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_textures[++i])
	{
		j = -1;
		while (map->map_textures[i][++j])
		{
			mlx_image_to_window(map->mlx, map->map_textures[i][j]->img, map->map_textures[i][j]->x_pos, map->map_textures[i][j]->y_pos);
		}
	}
}

void	ft_back_printer(t_map_data *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_textures[++i])
	{
		j = -1;
		while (map->map_textures[i][++j])
		{
			mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx, mlx_load_png(LAND_PATH)), map->map_textures[i][j]->x_pos, map->map_textures[i][j]->y_pos);
		}
	}
}