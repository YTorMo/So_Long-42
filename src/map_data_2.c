/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:55:26 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/12 13:15:24 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_ene	**ft_fill_enemies(char **p_map)
{
	t_ene	**enemies;

	enemies = malloc((sizeof(t_ene *) * ft_get_collec(p_map, 'N')) + 1);
	if (!enemies)
		return (NULL);
	ft_new_enemy(p_map, enemies);
	return (enemies);
}

void	ft_new_enemy(char **p_map, t_ene	**enemies)
{
	int		i[3];

	i[2] = -1;
	i[0] = -1;
	while (p_map[++i[0]])
	{
		i[1] = -1;
		while (p_map[i[0]][++i[1]])
		{
			if (p_map[i[0]][i[1]] == 'N')
			{
				if (++i[2] < ft_get_collec(p_map, 'N'))
				{
					enemies[i[2]] = malloc(sizeof(t_ene));
					if (!enemies[i[2]])
						return ;
					enemies[i[2]]->x_pos = i[1] * 64;
					enemies[i[2]]->y_pos = i[0] * 64;
				}
				else
					enemies[i[2]] = NULL;
			}
		}
	}
}
