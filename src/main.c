/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:01:17 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/05 12:42:37 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		perror("Los argumentos no son validos.");
	else
	{
		fd = open(ft_strjoin("./maps/", av[1]), O_RDONLY);
		if (fd < 0)
			perror("Fail: ");
		else if (!ft_check_file(av[1]))
			return (EXIT_FAILURE);
		else
		{
			//if(ft_map_checker(fd))
			ft_game_init(fd);
			close(fd);
		}
	}
	return (EXIT_SUCCESS);
}
