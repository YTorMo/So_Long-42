/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:32:38 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/13 09:38:19 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_enemy_patrol(t_map_data *map, int i)
{
	long	ene_dir;

	ene_dir = random();
	if (ene_dir <= RAND_MAX / 4)
		ft_key_up_ene(map, i);
	else if (ene_dir > (RAND_MAX / 4) && ene_dir <= (RAND_MAX / 2))
		ft_key_down_ene(map, i);
	else if (ene_dir > (RAND_MAX / 2) && ene_dir <= ((RAND_MAX / 4) * 3))
		ft_key_right_ene(map, i);
	else
		ft_key_left_ene(map, i);
}
