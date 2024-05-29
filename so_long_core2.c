/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_core2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:12:22 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 15:58:52 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_createedible(t_program program)
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
			if (program.map.map[i][j] == 'C')
			{
				mlx_put_image_to_window(program.mlx, program.window.reference,
					program.edible.reference, x, y);
			}
			j++;
			x += program.edible.size.x;
		}
		y += program.edible.size.y;
		i++;
	}
}

void	ft_door_check(t_program *program)
{
	program->collected = program->target
		- ft_count_in_map(program->map.map, 'C');
	if (program->collected == program->target)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->door.open.reference, program->door_position.x,
			program->door_position.y);
	else
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->door.close.reference, program->door_position.x,
			program->door_position.y);
}

void	ft_put_move(int move, int pos, t_program *program)
{
	ft_put_move1(move, pos, program);
	ft_put_move2(move, pos, program);
}

void	ft_print_move(int move, t_program *program)
{
	if (move > 999)
		ft_put_move((((move / 10) / 10) / 10) % 10, 0, program);
	if (move > 99)
		ft_put_move(((move / 10) / 10) % 10, 1, program);
	if (move > 9)
		ft_put_move((move / 10) % 10, 2, program);
	ft_put_move(move % 10, 3, program);
}

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	if (program->status == 0)
	{
		mlx_clear_window(program->mlx, program->window.reference);
		ft_input_core(program, key);
		ft_createwall(*program);
		ft_createfloor(*program);
		ft_door_check(program);
		ft_createedible(*program);
	}
	if (key == 65307)
		ft_close(program);
	return (0);
}
