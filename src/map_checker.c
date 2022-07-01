/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yago_42 <Yago_42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:57:29 by Yago_42           #+#    #+#             */
/*   Updated: 2022/07/01 20:41:10 by Yago_42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_map_checker(int fd)
{
    char    **map;

    map = ft_read_map(fd);
    if(!ft_check_comp(map))
    {
        ft_free_txt(map);
        return (0);
    }
    if(!ft_check_atleast(map))
    {
        ft_free_txt(map);
        return (0);
    }
    if(!ft_check_line_size(map))
    {
        ft_free_txt(map);
        return (0);
    }
    if(!ft_check_surrounded(map))
    {
        ft_free_txt(map);
        return (0);
    }
    ft_free_txt(map);
    return (1);
}

int ft_check_comp(char **map)
{
    int i;
    int j;
    
    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if(map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
            {
                perror("Error\nMap composition is incorrect.");
                return (0);
            }
        }
    }
    return (1);
}

int ft_check_atleast(char **map)
{
    int i;
    int j;
    int c1;
    int c2;
    int c3;
    
    i = -1;
    c1 = 0;
    c2 = 0;
    c3 = 0;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if(map[i][j] == 'C')
                c1++;
            if(map[i][j] == 'P')
                c2++;
            if(map[i][j] == 'E')
                c3++;
        }
    }
    if(!c1 || !c2 || !c3)
    {
        perror("Error\nThe map must contain at least 1 exit, 1 collectible, and 1 starting position.");
        return (0);
    }
    return (1);
}

int ft_check_line_size(char **map)
{
    int i;
    
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
}

/* int ft_check_line_size(char **map)
{
    int i;
    
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

int ft_check_surrounded(char **map)
{
    int i;
    
    i = -1;
    while (map[++i])
    {
        if(map[i][0] != '1' ||map[i][ft_strlen(map[i]) - 1] != '1')
        {
            perror("Error\nThe map is not surrounded by walls.");
            return (0);
        }
        if (i == 0 || i == ft_map_hth(map))
        {
            while (map[i])
            {
                if(*map[i] != '1')
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