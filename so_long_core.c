/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:52:30 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 15:27:21 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_move(t_program *program)
{
	static int	frame;

	frame++;
	ft_enemies_part(program, frame);
	if (frame == 32001)
		frame = 0;
}

int	ft_compare_vect(t_vector v1, t_vector v2)
{
	if (v1.x == v2.x && v1.y == v2.y)
		return (1);
	return (0);
}

void	ft_check_end(t_program *program)
{
	if (program->collected == program->target
		&& ft_compare_vect(program->door_position,
			program->sprite_position) == 1)
		program->status = 1;
	else if (ft_compare_vect(program->enemy_position,
			program->sprite_position) == 1)
		program->status = -1;
}

void	ft_createblack(t_program *program)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (program->map.map[i])
	{
		x = 0;
		j = 0;
		while (program->map.map[i][j])
		{
			mlx_put_image_to_window(program->mlx, program->window.reference,
				program->endgame.black.reference, x, y);
			j++;
			x += program->endgame.black.size.x;
		}
		y += program->endgame.black.size.y;
		i++;
	}
}

void	ft_end(t_program *program)
{	
	ft_createblack(program);
	if (program->status == -1)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->endgame.lose.reference, (program->window.size.x / 2)
			- (program->endgame.lose.size.x / 2), (program->window.size.y / 2)
			- program->endgame.lose.size.y);
	else
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->endgame.win.reference, (program->window.size.x / 2)
			- (program->endgame.win.size.x / 2), (program->window.size.y / 2)
			- program->endgame.win.size.y);
}
