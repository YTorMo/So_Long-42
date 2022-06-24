/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:39:04 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/24 10:33:35 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_wth(char **map)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (map[1][++i])
		count += 64;
	return (count);
}

int	ft_map_hth(char **map)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (map[++i])
		count += 64;
	return (count);
}
