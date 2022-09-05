/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:56:38 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/05 14:03:23 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_right(t_map_data *map)
{
	int	nxt_y;
	int	nxt_x;

	nxt_x = ((map->pj_init->x_pos) / 64) + 1;
	nxt_y = (map->pj_init->y_pos) / 64;
	if (ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, OBSTACLE_PATH, 69))
	{
		if (ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, EXIT_PATH,
			ft_strlen(EXIT_PATH)))
		{
			ft_mov_right(map, nxt_x, nxt_y);
		}
		else if (!(map->collec) && !(ft_strncmp(
					map->map_textures[nxt_y][nxt_x]->path,
				EXIT_PATH, ft_strlen(EXIT_PATH))))
		{
			ft_end_game_right(map, nxt_x, nxt_y);
		}
	}
}

void	ft_mov_right(t_map_data *map, int nxt_x, int nxt_y)
{
	ft_collec_check(map, nxt_x, nxt_y);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x]->img);
	mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx,
			mlx_load_png(PJR_PATH)), nxt_x * 64, nxt_y * 64);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x - 1]->img);
	mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx,
			mlx_load_png(LAND_PATH)), (nxt_x - 1) * 64, nxt_y * 64);
	ft_map_moves(map);
	map->pj_init->x_pos = nxt_x * 64;
}

void	ft_end_game_right(t_map_data *map, int nxt_x, int nxt_y)
{
	mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx,
			mlx_load_png(PJR_PATH)), nxt_x * 64, nxt_y * 64);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x - 1]->img);
	mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx,
			mlx_load_png(LAND_PATH)), (nxt_x - 1) * 64, nxt_y * 64);
	map->pj_init->y_pos = nxt_y * 64;
	mlx_close_window(map->mlx);
}
