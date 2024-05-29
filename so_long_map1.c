/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:13:31 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:17:05 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	ft_take_mapsize(char **map)
{
	t_vector	map_size;
	int			i;

	i = 0;
	map_size.x = ft_strlen(map[i]);
	while (map[i])
		i++;
	map_size.y = i;
	return (map_size);
}

char	**ft_cpymap(char **map)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (ft_mapcollen(map) + 1));
	while (map[i])
	{
		j = 0;
		result[i] = (char *)malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		while (map[i][j])
		{
			result[i][j] = map[i][j];
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_check_map_solution(char **map)
{
	char		**mapcpy;
	t_vector	*start;
	t_vector	size;
	int			i;

	i = 0;
	mapcpy = ft_cpymap(map);
	size.x = ft_strlen(map[0]);
	size.y = ft_mapcollen(map);
	start = ft_take_starting_dir(map, 'P', '0');
	while (i < 4)
	{
		ft_flood_fill(mapcpy, size, start[i]);
		if (ft_check_flooded_exit(mapcpy) == 0)
		{
			ft_free_map(mapcpy);
			return (0);
		}
		ft_free_map(mapcpy);
		mapcpy = ft_cpymap(map);
		i++;
	}
	free(start);
	ft_free_map(mapcpy);
	return (1);
}

int	ft_count_in_map(char **map, char element)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == element)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
