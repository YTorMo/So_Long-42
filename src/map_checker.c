/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:57:29 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/15 11:26:25 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_checker(char	*path)
{
	char	**map;
	int		fd;
	int		check;

	fd = open(path, O_RDONLY);
	map = ft_read_map(fd);
	if (!ft_check_comp(map))
	{
		ft_free_txt(map);
		return (0);
	}
	else
		check = ft_map_checker_2(map);
	close (fd);
	return (check);
}

int	ft_map_checker_2(char	**map)
{
	int		check;

	if (!ft_check_atleast(map, -1))
	{
		ft_free_txt(map);
		return (0);
	}
	if (!ft_check_line_size(map))
	{
		ft_free_txt(map);
		return (0);
	}
	if (!ft_check_surrounded(map))
	{
		ft_free_txt(map);
		return (0);
	}
	else
	{
		check = 1;
		ft_free_txt(map);
	}
	return (check);
}

int	ft_check_comp(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' &&
				map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'N')
			{
				ft_printf("Error\nMap composition is incorrect.\n");
				return (0);
			}
		}
	}
	return (1);
}

int	ft_check_atleast(char **map, int i)
{
	int	j;
	int	c[3];

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				c[0]++;
			if (map[i][j] == 'P')
				c[1]++;
			if (map[i][j] == 'E')
				c[2]++;
		}
	}
	if (!c[0] || !c[2] || c[1] != 1)
	{
		ft_printf("Error\nMap contents are not correct.\n");
		return (0);
	}
	return (1);
}
