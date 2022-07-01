/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yago_42 <Yago_42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:00:50 by Yago_42           #+#    #+#             */
/*   Updated: 2022/07/01 19:24:01 by Yago_42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_collec_check(t_map_data *map, int nxt_x, int nxt_y)
{
    if(!ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, COLLECTIBLE_PATH, ft_strlen(COLLECTIBLE_PATH)))
    {
        map->collec--;
        map->map_textures[nxt_y][nxt_x]->path = LAND_PATH;
        mlx_delete_image(map->mlx, map->txt_c);
        map->txt_c = mlx_put_string(map->mlx, ft_strjoin("ITEMS:	", ft_itoa(map->collec)), 110, map->map_hth);
    }
}