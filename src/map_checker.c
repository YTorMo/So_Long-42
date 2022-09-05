/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:57:29 by Yago_42           #+#    #+#             */
/*   Updated: 2022/09/05 12:45:34 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_checker(int fd)
{
	char	**map;

	map = ft_read_map(fd);
	if (!ft_check_comp(map))
	{
		ft_free_txt(map);
		return (0);
	}
	if (!ft_check_atleast(map))
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
	ft_free_txt(map);
	return (1);
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
				map[i][j] != 'E' && map[i][j] != 'P')
			{
				perror("Error\nMap composition is incorrect.");
				return (0);
			}
		}
	}
	return (1);
}

int	ft_check_atleast(char **map)
{
	int	i;
	int	j;
	int	*c;

	i = -1;
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	c = ft_check_atleast_2(map, c);
	if (!c[0] || !c[1] || !c[2])
	{
		perror("Error\nMap contents are not correct.");
		return (0);
	}
	return (1);
}

int	*ft_check_atleast_2(char **map, int *c)
{
	int	i;
	int	j;

	i = -1;
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
	return (c);
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
				perror("Error\nThe map is not a rectangle.");
				return (0);
			}
		}
	}
	return (1);
}
