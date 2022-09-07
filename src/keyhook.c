/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:15:06 by Yago_42           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/07 13:00:32 by ytoro-mo         ###   ########.fr       */
=======
/*   Updated: 2022/09/07 12:51:16 by ytoro-mo         ###   ########.fr       */
>>>>>>> 5b95221c5da9c010eb6d38234fd079a082af1e50
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_keyhook(mlx_key_data_t keydata, t_map_data *map)
{
<<<<<<< HEAD
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_key_up(map);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_key_down(map);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
=======
 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
    ft_key_up(map);
  if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
    ft_key_down(map);
  if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
>>>>>>> 5b95221c5da9c010eb6d38234fd079a082af1e50
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
<<<<<<< HEAD

void	ft_key_escape(t_map_data *map)
=======
  
void  ft_key_escape(t_map_data *map)
>>>>>>> 5b95221c5da9c010eb6d38234fd079a082af1e50
{
	mlx_close_window(map->mlx);
}

void	ft_map_moves(t_map_data *map)
{
<<<<<<< HEAD
	char	*moves;

	map->mov++;
	mlx_delete_image(map->mlx, map->txt);
	moves = ft_strjoin_3("MOVES:	", ft_itoa(map->mov));
	map->txt = mlx_put_string(map->mlx, moves, 0, map->map_hth);
	free(moves);
=======
    char  *moves;

    map->mov++;
    mlx_delete_image(map->mlx, map->txt);
    moves = ft_strjoin_3("MOVES:	", ft_itoa(map->mov));
    map->txt = mlx_put_string(map->mlx, moves, 0, map->map_hth);
    free (moves);
>>>>>>> 5b95221c5da9c010eb6d38234fd079a082af1e50
}
