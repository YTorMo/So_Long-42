/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:51:59 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/13 10:16:59 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_down(t_map_data *map)
{
	int	nxt_y;
	int	nxt_x;

	nxt_y = ((map->pj_init->y_pos) / 64) + 1;
	nxt_x = (map->pj_init->x_pos) / 64;
	if (!ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, ENEMY_PATH, 69))
	{
		ft_printf("TAS MUERTO\n");
		mlx_close_window(map->mlx);
	}
	if (ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, OBSTACLE_PATH, 69)
		&& ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, ENEMY_PATH, 69))
	{
		if (ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, EXIT_PATH,
			ft_strlen(EXIT_PATH)))
			ft_mov_down(map, nxt_x, nxt_y);
		else if (!(map->collec) && !(ft_strncmp(
					map->map_textures[nxt_y][nxt_x]->path,
				EXIT_PATH, ft_strlen(EXIT_PATH))))
		{
			ft_printf("\nHAS GANADO!!.\n");
			mlx_close_window(map->mlx);
		}
	}
	map->act_end = 0;
}

void	ft_mov_down(t_map_data *map, int nxt_x, int nxt_y)
{
	mlx_texture_t	*textu;

	ft_collec_check(map, nxt_x, nxt_y);
	textu = mlx_load_png(PJD_PATH);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x]->img);
	map->map_textures[nxt_y][nxt_x]->path = PJD_PATH;
	map->map_textures[nxt_y][nxt_x]->img = mlx_texture_to_image(map->mlx,
			textu);
	mlx_image_to_window(map->mlx, map->map_textures[nxt_y][nxt_x]->img,
		nxt_x * 64, nxt_y * 64);
	mlx_delete_texture(textu);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y - 1][nxt_x]->img);
	map->map_textures[nxt_y - 1][nxt_x]->img = NULL;
	map->map_textures[nxt_y - 1][nxt_x]->path = LAND_PATH;
	ft_map_moves(map);
	map->pj_init->y_pos = nxt_y * 64;
}

void	ft_key_down_2(t_map_data *map)
{
	int	nxt_y;
	int	nxt_x;

	nxt_y = ((map->pj_init->y_pos) / 64) + 1;
	nxt_x = (map->pj_init->x_pos) / 64;
	if (!ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, ENEMY_PATH, 69))
	{
		ft_printf("TAS MUERTO\n");
		mlx_close_window(map->mlx);
	}
	if (ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, OBSTACLE_PATH, 69)
		&& ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, ENEMY_PATH, 69))
	{
		if (ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, EXIT_PATH,
			ft_strlen(EXIT_PATH)))
			ft_mov_down_2(map, nxt_x, nxt_y);
		else if (!(map->collec) && !(ft_strncmp(
					map->map_textures[nxt_y][nxt_x]->path,
				EXIT_PATH, ft_strlen(EXIT_PATH))))
		{
			ft_printf("HAS GANADO!!.\n");
			mlx_close_window(map->mlx);
		}
	}
	map->act_end = 2;
}

void	ft_mov_down_2(t_map_data *map, int nxt_x, int nxt_y)
{
	mlx_texture_t	*textu;

	ft_collec_check(map, nxt_x, nxt_y);
	textu = mlx_load_png(PJD2_PATH);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x]->img);
	map->map_textures[nxt_y][nxt_x]->path = PJD2_PATH;
	map->map_textures[nxt_y][nxt_x]->img = mlx_texture_to_image(map->mlx,
			textu);
	mlx_image_to_window(map->mlx, map->map_textures[nxt_y][nxt_x]->img,
		nxt_x * 64, (nxt_y * 64) - 32);
	mlx_delete_texture(textu);
	mlx_delete_image(map->mlx, map->map_textures[nxt_y - 1][nxt_x]->img);
	map->map_textures[nxt_y - 1][nxt_x]->img = NULL;
	map->map_textures[nxt_y - 1][nxt_x]->path = LAND_PATH;
	map->prv_pjx = nxt_x;
	map->prv_pjy = nxt_y - 1;
}
