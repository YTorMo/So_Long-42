/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:18 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/15 11:06:45 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(int fd)
{
	t_map_data	*map;
	char		*item;

	map = ft_map_data(fd);
	map->mlx = mlx_init(map->map_wth, map->map_hth + 20, NAME_P, true);
	if (!map->mlx)
		exit(EXIT_FAILURE);
	ft_img_filler(map);
	ft_back_printer(map);
	ft_img_printer(map);
	map->txt = mlx_put_string(map->mlx, "MOVES:	0", 0, map->map_hth);
	item = ft_strjoin_3("ITEMS:	", ft_itoa(map->collec));
	map->txt_c = mlx_put_string(map->mlx, item, 110, map->map_hth);
	free(item);
	map->mov = 0;
	mlx_key_hook(map->mlx, (mlx_keyfunc)ft_keyhook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	map_struct_cleaner(map);
}

void	ft_img_filler(t_map_data *map)
{
	int				i;
	int				j;
	mlx_texture_t	*textu;

	i = -1;
	while (map->map_textures[++i])
	{
		j = -1;
		while (map->map_textures[i][++j])
		{
			textu = mlx_load_png(map->map_textures[i][j]->path);
			map->map_textures[i][j]->img = mlx_texture_to_image(map->mlx,
					textu);
			mlx_delete_texture(textu);
		}
	}
}

void	ft_img_printer(t_map_data *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_textures[++i])
	{
		j = -1;
		while (map->map_textures[i][++j])
		{
			mlx_image_to_window(map->mlx, map->map_textures[i][j]->img,
				map->map_textures[i][j]->x_pos, map->map_textures[i][j]->y_pos);
		}
	}
}

void	ft_back_printer(t_map_data *map)
{
	int				i;
	int				j;
	mlx_texture_t	*textu;

	i = -1;
	while (map->map_textures[++i])
	{
		j = -1;
		while (map->map_textures[i][++j])
		{
			textu = mlx_load_png(LAND_PATH);
			map->map_textures[i][j]->back_img = mlx_texture_to_image(map->mlx,
					textu);
			mlx_image_to_window(map->mlx, map->map_textures[i][j]->back_img,
				map->map_textures[i][j]->x_pos,
				map->map_textures[i][j]->y_pos);
			mlx_delete_texture(textu);
		}
	}
}
