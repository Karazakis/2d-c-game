/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:23:28 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:24:48 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_mapcollen(char **map)
{
	int	len;

	len = 0;
	while (map[len])
	{
		len++;
	}
	return (len);
}

int	ft_lineinfile(char *path)
{
	int		count;
	int		fd;
	int		i;
	char	buf[1];

	count = 0;
	i = 1;
	fd = open(path, O_RDONLY);
	while (i != 0)
	{
		i = read(fd, buf, 1);
		if (buf[0] == '\n')
			count++;
	}
	close(fd);
	count++;
	return (count);
}

void	ft_destroy_char(t_program program)
{
	mlx_destroy_image(program.mlx, program.enemy.walk1.reference);
	mlx_destroy_image(program.mlx, program.enemy.walk2.reference);
	mlx_destroy_image(program.mlx, program.enemy.walk3.reference);
	mlx_destroy_image(program.mlx, program.enemy.walk4.reference);
	mlx_destroy_image(program.mlx, program.enemy.walk5.reference);
	mlx_destroy_image(program.mlx, program.enemy.walk6.reference);
	mlx_destroy_image(program.mlx, program.hero.walk1.reference);
	mlx_destroy_image(program.mlx, program.hero.walk2.reference);
	mlx_destroy_image(program.mlx, program.hero.walk3.reference);
}

void	ft_destroy(t_program program)
{
	mlx_destroy_image(program.mlx, program.wall.reference);
	mlx_destroy_image(program.mlx, program.floor.reference);
	mlx_destroy_image(program.mlx, program.edible.reference);
	mlx_destroy_image(program.mlx, program.door.close.reference);
	mlx_destroy_image(program.mlx, program.door.open.reference);
	mlx_destroy_image(program.mlx, program.endgame.black.reference);
	mlx_destroy_image(program.mlx, program.endgame.win.reference);
	mlx_destroy_image(program.mlx, program.endgame.lose.reference);
	ft_destroy_char(program);
	mlx_destroy_image(program.mlx, program.number.zero);
	mlx_destroy_image(program.mlx, program.number.one);
	mlx_destroy_image(program.mlx, program.number.two);
	mlx_destroy_image(program.mlx, program.number.trhee);
	mlx_destroy_image(program.mlx, program.number.four);
	mlx_destroy_image(program.mlx, program.number.five);
	mlx_destroy_image(program.mlx, program.number.six);
	mlx_destroy_image(program.mlx, program.number.seven);
	mlx_destroy_image(program.mlx, program.number.eight);
	mlx_destroy_image(program.mlx, program.number.nine);
	mlx_destroy_window(program.mlx, program.window.reference);
}
