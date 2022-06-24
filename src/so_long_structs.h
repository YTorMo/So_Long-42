/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:06:00 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/24 12:49:02 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "so_long.h"

# define LAND_PATH "/Users/ytoro-mo/Documents/Cursus/SO_LONG/assets/Land2.png"
# define EXIT_PATH "/Users/ytoro-mo/Documents/Cursus/SO_LONG/assets/Exit_trns.png"
# define LAND_BASE_PATH "/Users/ytoro-mo/Documents/Cursus/SO_LONG/assets/Land_Base.png"
# define OBSTACLE_PATH "/Users/ytoro-mo/Documents/Cursus/SO_LONG/assets/Obstacle_roc.png"
# define COLLECTIBLE_PATH "/Users/ytoro-mo/Documents/Cursus/SO_LONG/assets/Collectible.png"

typedef struct s_map_tiles
{
	char					*path;
	int						x_pos;
	int						y_pos;
	struct s_map_tiles		*nxt;
}	t_map_tiles;

#endif
