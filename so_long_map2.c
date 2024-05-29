/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:17:27 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:19:39 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_sprite(char **map)
{
	int	hero;
	int	collect;
	int	exit;

	hero = ft_count_in_map(map, 'P');
	collect = ft_count_in_map(map, 'C');
	exit = ft_count_in_map(map, 'E');
	if (hero != 1 || collect < 2 || exit != 1 || ft_checksprite(map) != 1)
		return (1);
	return (0);
}

int	ft_checksprite(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_spriteallowed(map[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_load_map(t_program *program, char *path)
{
	program->map.map = ft_takemap(path);
	if (program->map.map == NULL)
	{
		program->error = 1;
		return ;
	}
	else if (ft_check_map(program->map.map) != 0)
	{
		program->error = 2;
		return ;
	}
	program->map.size = ft_take_mapsize(program->map.map);
	program->error = 0;
	return ;
}

int	ft_check_map(char **map)
{
	if (ft_check_map_dimension(map) != 0)
		return (1);
	if (ft_check_map_sprite(map) != 0 || ft_check_border(map) != 0)
		return (2);
	if (ft_check_map_solution(map) == 0)
		return (3);
	return (0);
}

int	ft_check_map_dimension(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		i++;
		if (map[i] && ft_strlen(map[i]) != len)
			return (1);
		if (map[i])
			len = ft_strlen(map[i]);
	}
	if (i < 3)
		return (2);
	return (0);
}
