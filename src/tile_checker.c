/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:00:50 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/12 13:25:40 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collec_check(t_map_data *map, int nxt_x, int nxt_y)
{
	char	*items;

	if (!ft_strncmp(map->map_textures[nxt_y][nxt_x]->path, COLLEC_PATH,
		ft_strlen(COLLEC_PATH)))
	{
		map->collec--;
		map->map_textures[nxt_y][nxt_x]->path = LAND_PATH;
		mlx_delete_image(map->mlx, map->txt_c);
		items = ft_strjoin_3("ITEMS:	", ft_itoa(map->collec));
		map->txt_c = mlx_put_string(map->mlx, items, 110, map->map_hth);
		free (items);
	}
}
