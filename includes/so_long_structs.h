/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:06:00 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/13 09:23:21 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "so_long.h"

# define LAND_PATH "./assets/Land2.png"
# define EXIT_PATH "./assets/exit_trs.png"
# define LAND_BASE_PATH "./assets/Land_Base.png"
# define OBSTACLE_PATH "./assets/Obs_trs.png"
# define COLLEC_PATH "./assets/collect.png"
# define PJR_PATH "./assets/bun_R.png"
# define PJR2_PATH "./assets/bun_R2.png"
# define PJL_PATH "./assets/bun_L.png"
# define PJL2_PATH "./assets/bun_L2.png"
# define PJU_PATH "./assets/bun_U.png"
# define PJU2_PATH "./assets/bun_U2.png"
# define PJD_PATH "./assets/bun_D.png"
# define PJD2_PATH "./assets/bun_D2.png"
# define ENEMY_PATH "./assets/ene.png"
# define GO_PATH "./assets/game_over.png"
# define NAME_P "CACUTXA AND THE LETXUGUITA QUEST."

typedef struct s_map_tiles
{
	char			*path;
	int				x_pos;
	int				y_pos;
	mlx_image_t		*img;
	mlx_image_t		*back_img;
}	t_map_tiles;

typedef struct s_pj
{
	char	*path;
	int		x_pos;
	int		y_pos;

}	t_pj;

typedef struct s_ene
{
	int		x_pos;
	int		y_pos;

}	t_ene;

typedef struct s_map_data
{
	t_map_tiles	***map_textures;
	int			collec;
	int			map_wth;
	int			map_hth;
	t_pj		*pj_init;
	mlx_t		*mlx;
	mlx_t		*mlx_go;
	mlx_image_t	*txt;
	int			mov;
	mlx_image_t	*txt_c;
	int			act_end;
	int			ene_mov;
	t_ene		**enemies;
	int			ene_num;
	int			ene_cuant;
	int			prv_pjx;
	int			prv_pjy;

}	t_map_data;

typedef struct s_img_cleaner
{
	mlx_image_t		**img;
}	t_img_cleaner;

#endif
