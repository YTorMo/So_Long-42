/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:55:26 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/09 13:59:23 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ene	**ft_fill_enemies(char **p_map)
{
	t_ene	**enemies;
	int		i;

	enemies = malloc((sizeof(t_ene *) * ft_get_collec(p_map, 'N')) + 1);
	if (!enemies)
		return (NULL);
	i = -1;
	while (++i < ft_get_collec(p_map, 'N'))
		enemies[i] = ft_new_enemy(p_map);
	enemies[i] = NULL;
	return (enemies);
}

t_ene	*ft_new_enemy(char **p_map)
{
	t_ene	*enemy;

	enemy = malloc(sizeof(t_ene));
	return (enemy);
}
