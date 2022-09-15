/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:40:37 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/06 09:07:03 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_4(char *s1, char *s2)
{
	char	*join;
	char	*memo;
	size_t	len;
	size_t	len_memo;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join || !s1 || !s2)
		return (NULL);
	memo = join;
	len = ft_strlen(s1);
	len_memo = len;
	while (len--)
		*memo++ = *s1++;
	s1 -= len_memo;
	len = ft_strlen(s2);
	len_memo = len;
	while (len--)
		*memo++ = *s2++;
	s2 -= len_memo;
	*memo = 0;
	free(s1);
	free(s2);
	return (join);
}

char	*ft_strjoin_3(char *s1, char *s2)
{
	char	*join;
	char	*memo;
	size_t	len;
	size_t	len_memo;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join || !s1 || !s2)
		return (NULL);
	memo = join;
	len = ft_strlen(s1);
	len_memo = len;
	while (len--)
		*memo++ = *s1++;
	s1 -= len_memo;
	len = ft_strlen(s2);
	len_memo = len;
	while (len--)
		*memo++ = *s2++;
	s2 -= len_memo;
	*memo = 0;
	free(s2);
	return (join);
}

char	*ft_strjoin_2(char *s1, char *s2)
{
	char	*join;
	char	*memo;
	size_t	len;
	size_t	len_memo;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join || !s1 || !s2)
		return (NULL);
	memo = join;
	len = ft_strlen(s1);
	len_memo = len;
	while (len--)
		*memo++ = *s1++;
	s1 -= len_memo;
	len = ft_strlen(s2);
	len_memo = len;
	while (len--)
		*memo++ = *s2++;
	s2 -= len_memo;
	*memo = 0;
	free(s1);
	return (join);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}