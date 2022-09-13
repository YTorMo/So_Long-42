/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_left_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:56 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/13 09:54:34 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_key_left_ene(t_map_data *map, int i)
{
	int	nxt_y;
	int	nxt_x;

	nxt_y = ((map->enemies[i]->y_pos) / 64);
	nxt_x = ((map->enemies[i]->x_pos) / 64) - 1;
	if (nxt_x == map->prv_pjx && nxt_y == map->prv_pjy)
		return ;
	if (!ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, PJR_PATH, 69)
		|| !ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, PJL_PATH, 69)
		|| !ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, PJU_PATH, 69)
		|| !ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, PJD_PATH, 69))
	{
		ft_printf("TAS MUERTO\n");
		mlx_close_window(map->mlx);
	}
	if (ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, OBSTACLE_PATH, 69)
		&& ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, ENEMY_PATH, 69)
		&& ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, EXIT_PATH, 69)
		&& ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, COLLEC_PATH, 69))
	{
		ft_mov_left_ene(map, nxt_x, nxt_y, i);
	}
}

void	ft_mov_left_ene(t_map_data *map, int nxt_x, int nxt_y, int i)
{
	mlx_texture_t	*textu;

	ft_collec_check(map, nxt_x, nxt_y);
	textu = mlx_load_png(ENEMY_PATH);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x]->img);
	map->map_textures[nxt_y][nxt_x]->path = ENEMY_PATH;
	map->map_textures[nxt_y][nxt_x]->img = mlx_texture_to_image(map->mlx,
			textu);
	mlx_image_to_window(map->mlx, map->map_textures[nxt_y][nxt_x]->img,
		nxt_x * 64, nxt_y * 64);
	mlx_delete_texture(textu);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x + 1]->img);
	map->map_textures[nxt_y][nxt_x + 1]->img = NULL;
	map->map_textures[nxt_y][nxt_x + 1]->path = LAND_PATH;
	map->enemies[i]->x_pos = nxt_x * 64;
}
