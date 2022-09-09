/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:44:13 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/09 13:50:08 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_struct_cleaner(t_map_data	*map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_textures[++i])
	{
		j = -1;
		while (map->map_textures[i][++j])
		{
			free(map->map_textures[i][j]->back_img);
			free(map->map_textures[i][j]->img);
			free(map->map_textures[i][j]);
		}
		free(map->map_textures[i]);
	}
	i = -1;
	while (map->enemies[++i])
		free(map->enemies[i]);
	free(map->enemies);
	free (map->txt);
	free (map->txt_c);
	free(map->map_textures);
	free(map->pj_init);
	free (map);
}
