/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:15:06 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/12 12:57:22 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_keyhook(mlx_key_data_t keydata, t_map_data *map)
{
	int	i;

	i = -1;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT) && map->act_end == 0)
		ft_key_up_2(map);
	else if (map->act_end == 1)
		ft_key_up(map);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT) && map->act_end == 0)
		ft_key_down_2(map);
	else if (map->act_end == 2)
		ft_key_down(map);
	else
		ft_keyhook_2(keydata, map);
	while (++i < map->ene_cuant)
		ft_enemy_patrol(map, i);
}

void	ft_keyhook_2(mlx_key_data_t keydata, t_map_data *map)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT) && map->act_end == 0)
		ft_key_right_2(map);
	else if (map->act_end == 3)
		ft_key_right(map);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT) && map->act_end == 0)
		ft_key_left_2(map);
	else if (map->act_end == 4)
		ft_key_left(map);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx);
}

void	ft_map_moves(t_map_data *map)
{
	char	*moves;

	map->mov++;
	mlx_delete_image(map->mlx, map->txt);
	moves = ft_strjoin_3("MOVES:	", ft_itoa(map->mov));
	map->txt = mlx_put_string(map->mlx, moves, 0, map->map_hth);
	free(moves);
}
