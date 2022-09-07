/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:01:49 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/07 12:49:35 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_left(t_map_data *map)
{
	int	nxt_y;
	int	nxt_x;

	nxt_x = ((map->pj_init->x_pos) / 64) - 1;
	nxt_y = (map->pj_init->y_pos) / 64;
	if (ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, OBSTACLE_PATH, 69))
	{
		if (ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, EXIT_PATH,
			ft_strlen(EXIT_PATH)))
		{
			ft_mov_left(map, nxt_x, nxt_y);
		}
		else if (!(map->collec) && !(ft_strncmp(
					map->map_textures[nxt_y][nxt_x]->path,
				EXIT_PATH, ft_strlen(EXIT_PATH))))
			mlx_close_window(map->mlx);
	}
}

void	ft_mov_left(t_map_data *map, int nxt_x, int nxt_y)
{
	mlx_texture_t	*textu;

	ft_collec_check(map, nxt_x, nxt_y);
	textu = mlx_load_png(PJL_PATH);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x]->img);
	map->map_textures[nxt_y][nxt_x]->img = mlx_texture_to_image(map->mlx,
			textu);
	mlx_image_to_window(map->mlx, map->map_textures[nxt_y][nxt_x]->img,
		nxt_x * 64, nxt_y * 64);
	mlx_delete_texture(textu);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x + 1]->img);
	map->map_textures[nxt_y][nxt_x + 1]->img = NULL;
	ft_map_moves(map);
	map->pj_init->x_pos = nxt_x * 64;
}
