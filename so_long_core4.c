/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_core4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:06:19 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:12:31 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_init_first(t_program *program)
{
	program->endgame.black.reference = mlx_xpm_file_to_image(program->mlx,
			"m/black.xpm", &program->endgame.black.size.x,
			&program->endgame.black.size.y);
	program->endgame.win.reference = mlx_xpm_file_to_image(program->mlx,
			"m/win.xpm", &program->endgame.win.size.x,
			&program->endgame.win.size.y);
	program->endgame.lose.reference = mlx_xpm_file_to_image(program->mlx,
			"m/lose.xpm", &program->endgame.lose.size.x,
			&program->endgame.lose.size.y);
	program->wall.reference = mlx_xpm_file_to_image(program->mlx,
			"m/walls.xpm", &program->wall.size.x,
			&program->wall.size.y);
	program->floor.reference = mlx_xpm_file_to_image(program->mlx,
			"m/floor.xpm", &program->floor.size.x,
			&program->floor.size.y);
	program->edible.reference = mlx_xpm_file_to_image(program->mlx,
			"m/edible.xpm", &program->edible.size.x,
			&program->edible.size.y);
}

void	ft_init_second(t_program *program)
{
	program->enemy.walk2.reference = mlx_xpm_file_to_image(program->mlx,
			"m/enemy2.xpm", &program->enemy.walk2.size.x,
			&program->enemy.walk2.size.y);
	program->enemy.walk3.reference = mlx_xpm_file_to_image(program->mlx,
			"m/enemy3.xpm", &program->enemy.walk3.size.x,
			&program->enemy.walk3.size.y);
	program->enemy.walk1.reference = mlx_xpm_file_to_image(program->mlx,
			"m/enemy1.xpm", &program->enemy.walk1.size.x,
			&program->enemy.walk1.size.y);
	program->enemy.walk4.reference = mlx_xpm_file_to_image(program->mlx,
			"m/enemy4.xpm", &program->enemy.walk4.size.x,
			&program->enemy.walk4.size.y);
	program->enemy.walk5.reference = mlx_xpm_file_to_image(program->mlx,
			"m/enemy5.xpm", &program->enemy.walk5.size.x,
			&program->enemy.walk5.size.y);
	program->enemy.walk6.reference = mlx_xpm_file_to_image(program->mlx,
			"m/enemy6.xpm", &program->enemy.walk6.size.x,
			&program->enemy.walk6.size.y);
}

void	ft_update_partial(t_program *program, int frame)
{
	ft_print_move(program->move, program);
	ft_enemy_move(program);
	if (frame >= 0 && frame <= 9000)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->hero.walk1.reference, program->sprite_position.x,
			program->sprite_position.y);
	else if (frame >= 9001 && frame <= 14000)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->hero.walk2.reference, program->sprite_position.x,
			program->sprite_position.y);
	else if (frame >= 14001 && frame <= 19000)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->hero.walk3.reference, program->sprite_position.x,
			program->sprite_position.y);
}

void	ft_enemies_part(t_program *program, int frame)
{
	if (frame >= 0 && frame <= 9000)
		mlx_put_image_to_window(program->mlx,
			program->window.reference, program->enemy.walk1.reference,
			program->enemy_position.x, program->enemy_position.y);
	else if (frame >= 9001 && frame <= 14000)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->enemy.walk2.reference, program->enemy_position.x,
			program->enemy_position.y);
	else if (frame >= 14001 && frame <= 19000)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->enemy.walk3.reference, program->enemy_position.x,
			program->enemy_position.y);
	else if (frame >= 19001 && frame <= 24000)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->enemy.walk4.reference, program->enemy_position.x,
			program->enemy_position.y);
	else if (frame >= 24001 && frame <= 29000)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->enemy.walk5.reference, program->enemy_position.x,
			program->enemy_position.y);
	else if (frame >= 29001 && frame <= 32000)
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->enemy.walk6.reference, program->enemy_position.x,
			program->enemy_position.y);
}

void	ft_input_core(t_program *program, int key)
{
	if (key == 65363 && program->map.map[program->sprite_position.y / 50]
		[(program->sprite_position.x / 50) + 1] != '1')
		program->sprite_position.x += program->hero.walk1.size.x;
	else if (key == 65361 && program->map.map
		[program->sprite_position.y / 50]
		[(program->sprite_position.x / 50) - 1] != '1')
		program->sprite_position.x -= program->hero.walk1.size.x;
	else if (key == 65364 && program->map.map
		[(program->sprite_position.y / 50) + 1]
		[program->sprite_position.x / 50] != '1')
		program->sprite_position.y += program->hero.walk1.size.y;
	else if (key == 65362 && program->map.map
		[(program->sprite_position.y / 50) - 1]
		[program->sprite_position.x / 50] != '1')
		program->sprite_position.y -= program->hero.walk1.size.y;
	if (key == 65362 || key == 65364 || key == 65361 || key == 65363)
		program->move++;
	if (program->map.map[program->sprite_position.y / 50]
		[program->sprite_position.x / 50] == 'C')
		program->map.map[program->sprite_position.y / 50]
		[program->sprite_position.x / 50] = '0';
}
