/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LibftHelper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imel-haj <imel-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:37:42 by slamhaou          #+#    #+#             */
/*   Updated: 2026/01/18 13:16:32 by imel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sin;
	int	num;

	i = 0;
	sin = 1;
	num = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sin *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sin);
}

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}

char	*str_dup(char *s)
{
	int		i;
	char	*arr;

	i = 0;
	arr = malloc(ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin(char *s1, char *lin)
{
	char	*arr;
	int		i;
	int		j;

	if (!s1 && lin)
	{
		arr = str_dup(lin);
		return (arr);
	}
	if (!lin && s1)
		return (s1);
	arr = malloc(ft_strlen(s1) + ft_strlen(lin) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		arr[j++] = s1[i++];
	i = 0;
	while (lin[i])
		arr[j++] = lin[i++];
	arr[j] = '\0';
	return (free(s1), arr);
}
