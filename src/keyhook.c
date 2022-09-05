/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:15:06 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/05 12:49:46 by ytoro-mo         ###   ########.fr       */
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

	// If we RELEASE the 'K' key, print "World".
	//if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
	//  puts("World");
  
void  ft_key_escape(t_map_data *map)
{
  mlx_close_window(map->mlx);
}

void  ft_map_moves(t_map_data *map)
{
    map->mov++;
    mlx_delete_image(map->mlx, map->txt);
    map->txt = mlx_put_string(map->mlx, ft_strjoin("MOVES:	", ft_itoa(map->mov)), 0, map->map_hth);
}
 