/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yago_42 <Yago_42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:06:00 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/07/01 19:18:22 by Yago_42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "so_long.h"

# define LAND_PATH "/Users/Yago_42/Documents/Cursus_casa/SO_LONG/assets/Land2.png"
# define EXIT_PATH "/Users/Yago_42/Documents/Cursus_casa/SO_LONG/assets/Exit_trns.png"
# define LAND_BASE_PATH "/Users/Yago_42/Documents/Cursus_casa/SO_LONG/assets/Land_Base.png"
# define OBSTACLE_PATH "/Users/Yago_42/Documents/Cursus_casa/SO_LONG/assets/Obstacle_trns.png"
# define COLLECTIBLE_PATH "/Users/Yago_42/Documents/Cursus_casa/SO_LONG/assets/Collectible_trns.png"
# define PJR_PATH "/Users/Yago_42/Documents/Cursus_casa/SO_LONG/assets/pj_r.png"
# define PJL_PATH "/Users/Yago_42/Documents/Cursus_casa/SO_LONG/assets/pj_l.png"
# define PJU_PATH "/Users/Yago_42/Documents/Cursus_casa/SO_LONG/assets/pj_u.png"
# define PJD_PATH "/Users/Yago_42/Documents/Cursus_casa/SO_LONG/assets/pj_d.png"

typedef struct s_map_tiles
{
	char			*path;
	int				x_pos;
	int				y_pos;
	mlx_image_t		*img;
}	t_map_tiles;

typedef struct s_pj
{
	char	*path;
	int		x_pos;
	int		y_pos;
	
}	t_pj;

typedef struct s_map_data
{
	t_map_tiles	***map_textures;
	int			collec;
	int			map_wth;
	int			map_hth;
	t_pj		*pj_init;
	mlx_t		*mlx;
	mlx_image_t	*txt;
	int			mov;
	mlx_image_t	*txt_c;
	
}	t_map_data;

#endif
