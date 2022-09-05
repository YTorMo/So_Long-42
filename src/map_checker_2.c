/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:11 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/05 12:44:37 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_surrounded(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			perror("Error\nThe map is not surrounded by walls.");
			return (0);
		}
		if (i == 0 || i == ft_map_hth(map))
		{
			while (map[i])
			{
				if (*map[i] != '1')
				{
					perror("Error\nThe map is not surrounded by walls.");
					return (0);
				}
				map[i]++;
			}
		}
	}
	return (1);
}
/* int ft_check_line_size(char **map)
{
    int i;
	int	i;
	int	i;

    
    i = -1;
    while (map[++i])
    {
        if(map[i + 1])
            if(ft_strlen(map[i]) != ft_strlen(map[i + 1]))
            {
                perror("Error\nThe map is not a rectangle.");
                return (0);
            }
    }
    return (1);
} */
