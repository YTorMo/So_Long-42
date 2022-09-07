/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:15:06 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/07 12:51:16 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_keyhook(mlx_key_data_t keydata, t_map_data *map)
{
 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
    ft_key_up(map);
  if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
    ft_key_down(map);
  if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_key_right(map);
  if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
    ft_key_left(map);
  if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    ft_key_escape(map);
  if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
    ft_key_up(map);
  if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
    ft_key_down(map);
  if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
    ft_key_right(map);
  if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
    ft_key_left(map);
}
  
void  ft_key_escape(t_map_data *map)
{
  mlx_close_window(map->mlx);
}

void  ft_map_moves(t_map_data *map)
{
    char  *moves;

    map->mov++;
    mlx_delete_image(map->mlx, map->txt);
    moves = ft_strjoin_3("MOVES:	", ft_itoa(map->mov));
    map->txt = mlx_put_string(map->mlx, moves, 0, map->map_hth);
    free (moves);
}
 