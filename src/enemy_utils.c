/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:35:58 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/12 17:06:25 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_paths(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 8);
	if (!paths)
		return (NULL);
	paths[0] = PJR_PATH;
	paths[1] = PJR2_PATH;
	paths[2] = PJL_PATH;
	paths[3] = PJL2_PATH;
	paths[4] = PJU_PATH;
	paths[5] = PJU2_PATH;
	paths[6] = PJD_PATH;
	paths[7] = PJD2_PATH;
	return (paths);
}

int	ft_is_nxt_pj(char	*check_path)
{
	char	**paths;
	int		i;
	int		ok;

	paths = ft_paths();
	i = -1;
	ok = 0;
	while (++i < 8)
	{
		if (ft_strncmp(check_path, paths[i], ft_strlen(paths[i])))
		{
			ok = 1;
		}
	}
	free(paths);
	return (ok);
}
