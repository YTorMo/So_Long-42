/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:46:35 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/05 12:43:12 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file(char *file)
{
	int	ok;

	ok = 1;
	if (!ft_strnstr(file, ".ber", ft_strlen(file)))
	{
		ok = 0;
		write(2, "Wrong file extension.", 21);
	}
	return (ok);
}
