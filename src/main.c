/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:01:17 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/15 11:13:15 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int ac, char **av)
{
	int		fd;
	char	*path;

	if (ac != 2)
		ft_printf("Los argumentos no son validos.");
	else
	{
		path = ft_strjoin("./maps/", av[1]);
		fd = open(path, O_RDONLY);
		free(path);
		if (fd < 0)
			ft_printf("Fail: ");
		else if (!ft_check_file(av[1]))
			return (EXIT_FAILURE);
		else
			game_init(fd, av[1]);
	}
	system("leaks -q so_long");
	return (EXIT_SUCCESS);
}
	//fscanf(stdin, "c");

void	game_init(int fd, char *file)
{
	char	*path;

	path = ft_strjoin("./maps/", file);
	if (ft_map_checker(path))
	{				
		ft_printf("Map is correct.\n");
		ft_game_init(fd);
	}
	free (path);
	close(fd);
}
