/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:34:31 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:43:18 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_update(void *param)
{
	t_program	*program;
	static int	frame;

	program = (t_program *)param;
	if (program->status == 0)
		ft_check_end(program);
	if (program->status == 0)
	{
		frame++;
		ft_update_partial(program, frame);
		if (frame == 24001)
			frame = 0;
	}
	else
		ft_end(program);
	return (0);
}

void	ft_init_everybody(t_program *program)
{
	program->hero.walk2.reference = mlx_xpm_file_to_image(program->mlx,
			"m/walk2.xpm", &program->hero.walk2.size.x,
			&program->hero.walk2.size.y);
	program->hero.walk1.reference = mlx_xpm_file_to_image(program->mlx,
			"m/walk1.xpm", &program->hero.walk1.size.x,
			&program->hero.walk1.size.y);
	program->hero.walk3.reference = mlx_xpm_file_to_image(program->mlx,
			"m/walk3.xpm", &program->hero.walk3.size.x,
			&program->hero.walk3.size.y);
	program->door.close.reference = mlx_xpm_file_to_image(program->mlx,
			"m/doorclosed.xpm", &program->door.close.size.x,
			&program->door.close.size.y);
	program->door.open.reference = mlx_xpm_file_to_image(program->mlx,
			"m/dooropen.xpm", &program->door.open.size.x,
			&program->door.open.size.y);
	ft_init_first(program);
	ft_init_second(program);
}

void	ft_init_number(t_program *program)
{
	program->number.zero = mlx_xpm_file_to_image(program->mlx, "m/zero.xpm",
			&program->number.x, &program->number.y);
	program->number.one = mlx_xpm_file_to_image(program->mlx, "m/uno.xpm",
			&program->number.x, &program->number.y);
	program->number.two = mlx_xpm_file_to_image(program->mlx, "m/due.xpm",
			&program->number.x, &program->number.y);
	program->number.trhee = mlx_xpm_file_to_image(program->mlx, "m/tre.xpm",
			&program->number.x, &program->number.y);
	program->number.four = mlx_xpm_file_to_image(program->mlx, "m/qua.xpm",
			&program->number.x, &program->number.y);
	program->number.five = mlx_xpm_file_to_image(program->mlx, "m/cinq.xpm",
			&program->number.x, &program->number.y);
	program->number.six = mlx_xpm_file_to_image(program->mlx, "m/sei.xpm",
			&program->number.x, &program->number.y);
	program->number.seven = mlx_xpm_file_to_image(program->mlx, "m/sette.xpm",
			&program->number.x, &program->number.y);
	program->number.eight = mlx_xpm_file_to_image(program->mlx, "m/otto.xpm",
			&program->number.x, &program->number.y);
	program->number.nine = mlx_xpm_file_to_image(program->mlx, "m/nove.xpm",
			&program->number.x, &program->number.y);
}

void	ft_load_evoirment(t_program *program, char **argv)
{
	ft_load_map(program, argv[1]);
	if (program->error != 0)
	{
		ft_free_map(program->map.map);
		return ;
	}
	program->sprite_position = ft_take_pos(program->map.map, 'P');
	program->enemy_position = ft_take_pos(program->map.map, 'A');
	program->door_position = ft_take_pos(program->map.map, 'E');
	program->mlx = mlx_init();
	program->window = ft_new_window(program->mlx, program->map.size.x * 50,
			program->map.size.y * 50, "diahaninos");
	ft_init_everybody(program);
	ft_init_number(program);
	program->target = ft_count_in_map(program->map.map, 'C');
	program->status = 0;
	program->move = 0;
	program->collected = 0;
	ft_createwall(*program);
	ft_createfloor(*program);
	ft_createedible(*program);
}

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc != 2)
	{
		ft_putstr("Hai messo troppi o troppo pochi,\
				argomenti ciccino, non fare il ganzino\n");
		return (0);
	}
	ft_load_evoirment(&program, argv);
	if (program.error != 0)
	{
		ft_putstr("Controlla che mappa t'hai messo vai,\
			abbozzala di fare il grullo\n");
		return (0);
	}
	program.sprite_position.x *= 50;
	program.sprite_position.y *= 50;
	program.enemy_position.y *= 50;
	program.enemy_position.x *= 50;
	program.door_position.y *= 50;
	program.door_position.x *= 50;
	program.num_pos.x = program.window.size.x * 0.1;
	program.num_pos.y = 0;
	mlx_key_hook(program.window.reference, *ft_input, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_hook(program.window.reference, 17, 0, ft_close, &program);
	mlx_loop(program.mlx);
}
