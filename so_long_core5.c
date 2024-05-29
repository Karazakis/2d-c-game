/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_core5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:13:07 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:13:09 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_put_move1(int move, int pos, t_program *program)
{
	if (move == 0)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.zero, program->num_pos.x + (50 * pos),
			program->num_pos.y);
	else if (move == 1)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.one, program->num_pos.x + (50 * pos),
			program->num_pos.y);
	else if (move == 2)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.two, program->num_pos.x + (50 * pos),
			program->num_pos.y);
	else if (move == 3)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.trhee, program->num_pos.x + (50 * pos),
			program->num_pos.y);
	else if (move == 4)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.four, program->num_pos.x + (50 * pos),
			program->num_pos.y);
}

void	ft_put_move2(int move, int pos, t_program *program)
{
	if (move == 5)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.five, program->num_pos.x + (50 * pos),
			program->num_pos.y);
	else if (move == 6)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.six, program->num_pos.x + (50 * pos),
			program->num_pos.y);
	else if (move == 7)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.seven, program->num_pos.x + (50 * pos),
			program->num_pos.y);
	else if (move == 8)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.eight, program->num_pos.x + (50 * pos),
			program->num_pos.y);
	else if (move == 9)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->number.nine, program->num_pos.x + (50 * pos),
			program->num_pos.y);
}
