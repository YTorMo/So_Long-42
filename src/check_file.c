/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:46:35 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/12 13:06:54 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file(char *file)
{
	int		ok;
	char	*temp;

	ok = 1;
	temp = file;
	temp += ft_strlen(temp) - 4;
	if (!ft_strnstr(temp, ".ber", ft_strlen(temp)))
	{
		ok = 0;
		write(2, "Wrong file extension.", 21);
	}
	return (ok);
}
