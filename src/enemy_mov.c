/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:32:38 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/09 13:37:29 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_patrol(t_map_data *map)
{
	long	ene_dir;

	ene_dir = random();
	if (ene_dir <= RAND_MAX / 4)												//UP
		ft_ene_mov(map, int *dir, int x, int y);
	else if (ene_dir > (RAND_MAX / 4) && ene_dir <= (RAND_MAX / 2))				//DOWN
		ft_ene_mov(map, int *dir, int x, int y);
	else if (ene_dir > (RAND_MAX / 2) && ene_dir <= ((RAND_MAX / 4) * 3))		//RIGHT
		ft_ene_mov(map, int *dir, int x, int y);
	else																		//LEFT
		ft_ene_mov(map, int *dir, int x, int y);
	//temporal
	sleep(1);
}

void	ft_ene_mov(t_map_data *map, int *dir, int *xy, int *nxt_nxt)
{
	int		nxt_pj;
	int		*nxt;

	nxt[0] = ((map->pj_init->y_pos) / 64) + xy[0];
	nxt[1] = ((map->pj_init->x_pos) / 64) + xy[1];
	nxt_pj = ft_is_nxt_pj(map->map_textures[nxt[0]][nxt[1]]->path);
	if (ft_strncmp(map->map_textures[nxt[0]][nxt[1]]->path, OBSTACLE_PATH, 69)
		&& ft_strncmp(map->map_textures[nxt[0]][nxt[1]]->path, EXIT_PATH, 69)
		&& nxt_pj)
	{
		ft_ene_mov_2(map, nxt, dir, nxt_nxt);
	}
	else if (!nxt_pj)
	{
		ft_printf("TAS MUERTO\n");
		mlx_close_window(map->mlx);
	}
}

void	ft_ene_mov_2(t_map_data *map, int *nxt, int *dir, int *nxt_nxt)
{
	mlx_texture_t	*textu;

	ft_collec_check(map, nxt[1], nxt[0]);
	textu = mlx_load_png(ENEMY_PATH);
	mlx_delete_image(map->mlx, map->map_textures[nxt[0]][nxt[1]]->img);
	map->map_textures[nxt[0]][nxt[1]]->img = mlx_texture_to_image(map->mlx,
			textu);
	mlx_image_to_window(map->mlx, map->map_textures[nxt[0]][nxt[1]]->img,
		(nxt[1] * 64) + dir[1], (nxt[0] * 64) + dir[0]);
	mlx_delete_texture(textu);
	mlx_delete_image(map->mlx,
		map->map_textures[nxt[0] + nxt_nxt[0]][nxt[1] + nxt_nxt[1]]->img);
	map->map_textures[nxt[0] + nxt_nxt[0]][nxt[1] + nxt_nxt[1]]->img = NULL;
	map->enemies[map->ene_num]->y_pos = nxt[0] * 64;
	map->enemies[map->ene_num]->x_pos = nxt[1] * 64;
}

char	**ft_paths(void)
{
	char	**paths;

	paths[0] = PJR_PATH;
	paths[1] = PJR2_PATH;
	paths[2] = PJL_PATH;
	paths[3] = PJL2_PATH;
	paths[4] = PJU_PATH;
	paths[5] = PJU2_PATH;
	paths[6] = PJD_PATH;
	paths[7] = PJD2_PATH;
	paths[8] = ENEMY_PATH;
	return (paths);
}

int	ft_is_nxt_pj(char	**check_path)
{
	char	**paths;
	int		i;

	paths = ft_paths();
	i = -1;
	while (++i < 9)
	{
		if (!ft_strncmp(check_path, paths[i], 69))
			return (0);
	}
	return (1);
}
