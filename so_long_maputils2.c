/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_maputils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:20:49 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:23:10 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	*ft_take_starting_dir(char **map, char check, char checked)
{
	t_vector	hero;
	t_vector	*result;
	int			count;
	int			i;

	i = 0;
	hero = ft_take_pos(map, check);
	count = ft_elem_dir_count(map, hero, checked);
	result = malloc(sizeof(t_vector) * count);
	if (map[hero.y][hero.x + 1] && map[hero.y][hero.x + 1] == checked)
		result[i++] = ft_add_vect_list(hero.y, hero.x + 1);
	if (map[hero.y][hero.x - 1] && map[hero.y][hero.x - 1] == checked)
		result[i++] = ft_add_vect_list(hero.y, hero.x - 1);
	if (map[hero.y + 1][hero.x] && map[hero.y + 1][hero.x] == checked)
		result[i++] = ft_add_vect_list(hero.y + 1, hero.x);
	if (map[hero.y - 1][hero.x] && map[hero.y - 1][hero.x] == checked)
		result[i++] = ft_add_vect_list(hero.y - 1, hero.x);
	return (result);
}

int	ft_check_flooded_exit(char **map)
{
	int			count;
	t_vector	exit;

	exit = ft_take_pos(map, 'E');
	count = ft_elem_dir_count(map, exit, 'F');
	return (count);
}

int	ft_check_border(char **map)
{
	int	i;
	int	j;
	int	li;
	int	lj;

	i = 0;
	li = ft_strlen(map[i]);
	lj = ft_mapcollen(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || j == 0 || j == lj || i == li)
				if (map[i][j] != '1')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_spriteallowed(char c)
{
	if (c == '1' || c == 'P' || c == 'A' || c == 'E' || c == '0' || c == 'C')
		return (1);
	return (0);
}

int	ft_close(t_program *program)
{
	ft_free_map(program->map.map);
	ft_destroy(*program);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	exit(0);
}
