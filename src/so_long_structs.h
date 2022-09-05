/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:06:00 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/05 08:56:07 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "so_long.h"

# define LAND_PATH "../assets/Land2.png"
# define EXIT_PATH "../assets/exit_trs.png"
# define LAND_BASE_PATH "../assets/Land_Base.png"
# define OBSTACLE_PATH "../assets/Obs_trs.png"
# define COLLECTIBLE_PATH "../assets/collect.png"
# define PJR_PATH "../assets/bun_R.png"
# define PJL_PATH "../assets/bun_L.png"
# define PJU_PATH "../assets/bun_U.png"
# define PJD_PATH "../assets/bun_D.png"

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
