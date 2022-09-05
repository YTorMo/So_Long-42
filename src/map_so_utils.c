/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_so_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:39:04 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/05 12:41:55 by ytoro-mo         ###   ########.fr       */
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

void	ft_free_txt(char **txt)
{
	int	i;

	i = -1;
	while (txt[++i])
	{
		free(txt[i]);
	}
	free(txt);
}
