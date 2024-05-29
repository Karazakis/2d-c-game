/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_maputils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:20:20 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:20:23 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_vector size, t_vector cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_vector){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_vector){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_vector){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_vector){cur.x, cur.y + 1}, to_fill);
}

void	ft_flood_fill(char **tab, t_vector size, t_vector begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

t_vector	ft_add_vect_list(int y, int x)
{
	t_vector	list;

	list.x = x;
	list.y = y;
	return (list);
}

t_vector	ft_take_pos(char **map, char elem)
{
	t_vector	result;
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == elem)
			{
				result.x = j;
				result.y = i;
			}
			j++;
		}
		i++;
	}
	return (result);
}

int	ft_elem_dir_count(char **map, t_vector hero, char elem)
{
	int	count;

	count = 0;
	if (map[hero.y][hero.x + 1] && map[hero.y][hero.x + 1] == elem)
		count++;
	if (map[hero.y][hero.x - 1] && map[hero.y][hero.x - 1] == elem)
		count++;
	if (map[hero.y + 1][hero.x] && map[hero.y + 1][hero.x] == elem)
		count++;
	if (map[hero.y - 1][hero.x] && map[hero.y - 1][hero.x] == elem)
		count++;
	return (count);
}
