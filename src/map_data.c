/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:41:33 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/13 09:36:24 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_data	*ft_map_data(int fd)
{
	t_map_data	*map;
	char		**proto_map;

	map = malloc(sizeof(t_map_data));
	if (!map)
		return (NULL);
	proto_map = ft_read_map(fd);
	map->map_wth = ft_map_wth(proto_map);
	map->map_hth = ft_map_hth(proto_map);
	map->collec = ft_get_collec(proto_map, 'C');
	map->ene_cuant = ft_get_collec(proto_map, 'N');
	map->map_textures = ft_map_texture(map->map_wth / 64, map->map_hth / 64,
			proto_map);
	map->pj_init = ft_get_init_pj(proto_map);
	map->act_end = 0;
	map->enemies = ft_fill_enemies(proto_map);
	map->prv_pjx = map->pj_init->x_pos;
	map->prv_pjy = map->pj_init->y_pos;
	ft_free_txt(proto_map);
	return (map);
}

char	**ft_read_map(int fd)
{
	char	**map;
	char	*line;

	line = get_next_line_c(fd);
	while (line[ft_strlen(line) - 1] == '\n')
		line = ft_strjoin_4(line, get_next_line_c(fd));
	map = ft_split_2(line, '\n');
	free(line);
	return (map);
}

int	ft_get_collec(char **p_map, char c)
{
	int	i;
	int	j;
	int	collec;

	collec = 0;
	i = -1;
	while (p_map[++i])
	{
		j = -1;
		while (p_map[i][++j])
		{
			if (p_map[i][j] == c)
				collec++;
		}
	}
	return (collec);
}

t_pj	*ft_get_init_pj(char **p_map)
{
	int		i;
	int		j;
	t_pj	*pj;

	i = -1;
	pj = malloc(sizeof(t_pj));
	if (!pj)
		return (NULL);
	while (p_map[++i])
	{
		j = -1;
		while (p_map[i][++j])
		{
			if (p_map[i][j] == 'P')
			{
				pj->path = PJR_PATH;
				pj->x_pos = j * 64;
				pj->y_pos = i * 64;
			}
		}
	}
	return (pj);
}
