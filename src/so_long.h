/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:05:04 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/24 12:11:10 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../lib/MLX42_/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "so_long_structs.h"

void		ft_read_map(int fd);
int			ft_check_file(char *file);
void		ft_print_map(char **map);
t_map_tiles	***ft_map_texture(int size_l, int size_c);
t_map_tiles	**ft_map_line(int size);
char		*ft_texture_selector(char c);
int			ft_map_wth(char **map);
int			ft_map_hth(char **map);

#endif
