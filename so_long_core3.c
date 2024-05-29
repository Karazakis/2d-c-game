/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_core3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:37 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:05:40 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, ft_close, 0);
	return (window);
}

void	ft_createwall(t_program program)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (program.map.map[i])
	{
		x = 0;
		j = 0;
		while (program.map.map[i][j])
		{
			if (program.map.map[i][j] == '1')
			{
				mlx_put_image_to_window(program.mlx, program.window.reference,
					program.wall.reference, x, y);
			}
			j++;
			x += program.wall.size.x;
		}
		y += program.wall.size.y;
		i++;
	}
}

void	ft_createfloor(t_program program)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (program.map.map[i])
	{
		x = 0;
		j = 0;
		while (program.map.map[i][j])
		{
			if (program.map.map[i][j] != '1')
			{
				mlx_put_image_to_window(program.mlx, program.window.reference,
					program.floor.reference, x, y);
			}
			j++;
			x += program.floor.size.x;
		}
		y += program.floor.size.y;
		i++;
	}
}

char	**ft_takemap(char *path)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (ft_lineinfile(path) + 1));
	fd = open(path, O_RDONLY);
	map[i] = ft_get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = ft_get_next_line(fd);
	}
	return (map);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
