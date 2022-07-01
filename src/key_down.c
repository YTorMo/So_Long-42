/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yago_42 <Yago_42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:51:59 by Yago_42           #+#    #+#             */
/*   Updated: 2022/07/01 19:13:01 by Yago_42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_key_down(t_map_data *map)
{
  int         nxt_y;
  int         nxt_x;
  
  nxt_y = ((map->pj_init->y_pos) / 64) + 1;
  nxt_x = (map->pj_init->x_pos) / 64;
  if(ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, OBSTACLE_PATH, 69))
    {
      if(ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, EXIT_PATH, ft_strlen(EXIT_PATH)))
      {
        ft_mov_down(map, nxt_x, nxt_y);
      }
      else if (!(map->collec) && !(ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, EXIT_PATH, ft_strlen(EXIT_PATH))))
      {
        ft_end_game_down(map, nxt_x, nxt_y);
      }
    }
}

void  ft_mov_down(t_map_data *map, int nxt_x, int nxt_y)
{
    ft_collec_check(map, nxt_x, nxt_y);
    mlx_delete_image(map->mlx, map->map_textures[nxt_y][nxt_x]->img);
    mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx, mlx_load_png(PJD_PATH)), nxt_x * 64 , nxt_y * 64);
    mlx_delete_image(map->mlx, map->map_textures[nxt_y - 1][nxt_x]->img);
    mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx, mlx_load_png(LAND_PATH)), nxt_x * 64 , (nxt_y - 1) * 64);
    ft_map_moves(map);
    map->pj_init->y_pos = nxt_y * 64;
}

void  ft_end_game_down(t_map_data *map, int nxt_x, int nxt_y)
{
  mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx, mlx_load_png(PJD_PATH)), nxt_x * 64 , nxt_y * 64);
  mlx_delete_image(map->mlx, map->map_textures[nxt_y - 1][nxt_x]->img);
  mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx, mlx_load_png(LAND_PATH)), nxt_x * 64 , (nxt_y - 1) * 64);
  map->pj_init->y_pos = nxt_y * 64;
  mlx_close_window(map->mlx);
}