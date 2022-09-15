/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:11 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/15 11:26:14 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_surrounded(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			ft_printf("Error\nThe map is not surrounded by walls.\n");
			return (0);
		}
		if (i == 0 || !map[i + 1])
		{
			j = -1;
			while (map[i][++j])
			{
				if (map[i][j] != '1')
				{
					ft_printf("Error\nThe map is not surrounded by walls.\n");
					return (0);
				}
			}
		}
	}
	return (1);
}

int	ft_check_line_size(char **map)
{
	int	i;
	int	a;
	int	b;

	i = -1;
	while (map[++i])
	{
		if (map[i + 1])
		{
			a = ft_strlen(map[i]);
			b = ft_strlen(map[i + 1]);
			if (a != b)
			{
				ft_printf("Error\nThe map is not a rectangle.\n");
				return (0);
			}
		}
	}
	return (1);
}
