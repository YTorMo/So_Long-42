/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:43:32 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/06 15:01:33 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_size(int n);

char	*ft_itoa(int n)
{
	char	*num;
	size_t	size;
	long	long_n;

	size = ft_num_size(n);
	num = malloc(size + 1);
	if (!num)
		return (NULL);
	num[size--] = 0;
	if (n == 0)
		num[0] = '0';
	if (n < 0)
	{
		long_n = -(long)n;
		num[0] = '-';
	}
	else
		long_n = n;
	while (long_n > 0)
	{
		num[size--] = (long_n % 10) + 48;
		long_n = long_n / 10;
	}
	return (num);
}

static size_t	ft_num_size(int n)
{
	size_t	i;
	size_t	n_pos;

	i = 0;
	if (n <= 0)
	{
		n_pos = -(size_t)n;
		i++;
	}
	else
		n_pos = n;
	while (n_pos > 0)
	{
		n_pos = n_pos / 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_number_size(int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length += 1;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa_2(int n)
{
	char			*string;
	unsigned int	number;
	unsigned int	length;

	length = ft_number_size(n);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	if (n < 0)
	{
		string[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		string[0] = '0';
	string[length] = '\0';
	while (number != 0)
	{
		string[length - 1] = (number % 10) + '0';
		number = number / 10;
		length--;
	}
	return (string);
}
