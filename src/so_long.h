/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:05:04 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/06 14:00:35 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42_/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "so_long_structs.h"
# include <fcntl.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		**ft_read_map(int fd);
int			ft_check_file(char *file);
t_map_tiles	***ft_map_texture(int size_l, int size_c, char **map);
t_map_tiles	**ft_map_line(int size, char *line, int y);
char		*ft_texture_path(char c);
int			ft_map_wth(char **map);
int			ft_map_hth(char **map);
t_map_data	*ft_map_data(int fd);
int			ft_get_collec(char **p_map);
t_pj		*ft_get_init_pj(char **p_map);
void		ft_game_init(int fd);
void		ft_keyhook(mlx_key_data_t keydata, t_map_data *map);
void		ft_img_filler(t_map_data *map);
void		ft_back_printer(t_map_data *map);
void		ft_img_printer(t_map_data *map);
void		ft_key_up(t_map_data *map);
void		ft_mov_up(t_map_data *map, int nxt_x, int nxt_y);
void		ft_end_game_up(t_map_data *map, int nxt_x, int nxt_y);
void		ft_key_down(t_map_data *map);
void		ft_mov_down(t_map_data *map, int nxt_x, int nxt_y);
void		ft_end_game_down(t_map_data *map, int nxt_x, int nxt_y);
void		ft_key_right(t_map_data *map);
void		ft_mov_right(t_map_data *map, int nxt_x, int nxt_y);
void		ft_end_game_right(t_map_data *map, int nxt_x, int nxt_y);
void		ft_key_left(t_map_data *map);
void		ft_mov_left(t_map_data *map, int nxt_x, int nxt_y);
void		ft_end_game_left(t_map_data *map, int nxt_x, int nxt_y);
void		ft_key_escape(t_map_data *map);
void		ft_collec_check(t_map_data *map, int nxt_x, int nxt_y);
void		ft_map_moves(t_map_data *map);
void		ft_free_txt(char **txt);
int			ft_map_checker(char	**path);
int			ft_map_checker_2(char	**map);
int			ft_check_comp(char **map);
int			ft_check_atleast(char **map, int i);
int			ft_check_line_size(char **map);
void		game_init(int fd, char **file);
void		map_struct_cleaner(t_map_data	*map);

#endif
