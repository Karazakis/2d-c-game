/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <akoutsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:25:16 by akoutsou          #+#    #+#             */
/*   Updated: 2022/12/16 16:36:33 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_vectors
{
	int	x;
	int	y;
}				t_vectors;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_image
{
	void		*reference;
	t_vector	size;

}				t_image;

typedef struct s_images
{
	void		*reference;
	t_vector	size;
}				t_images;

typedef struct s_map
{
	char		**map;
	t_vector	size;
}				t_map;

typedef struct s_char
{
	t_image		walk1;
	t_image		walk2;
	t_image		walk3;
	t_image		walk4;
	t_image		walk5;
	t_image		walk6;
}				t_char;

typedef struct s_door {
	t_image		open;
	t_image		close;
}				t_door;

typedef struct s_number {
	void		*one;
	void		*two;
	void		*trhee;
	void		*four;
	void		*five;
	void		*six;
	void		*seven;
	void		*eight;
	void		*nine;
	void		*zero;
	int			x;
	int			y;
}				t_number;

typedef struct s_endgame {
	t_images		black;
	t_images		win;
	t_images		lose;
}				t_endgame;

typedef struct s_program {
	void		*mlx;
	t_window	window;
	t_image		wall;
	t_image		floor;
	t_image		edible;
	t_char		hero;
	t_char		enemy;
	t_door		door;
	t_number	number;
	t_vector	sprite_position;
	t_vector	enemy_position;
	t_vector	door_position;
	t_vector	num_pos;
	t_map		map;
	t_endgame	endgame;
	int			collected;
	int			target;
	int			error;
	int			status;
	int			move;
}				t_program;

int			ft_input(int key, void *param);
int			ft_lineinfile(char *path);
int			ft_mapcollen(char **map);
int			ft_strlen(char *str);
int			ft_update(void *param);
int			ft_check_map_solution(char **map);
int			ft_count_in_map(char **map, char element);
int			ft_elem_dir_count(char **map, t_vector hero, char elem);
int			ft_check_flooded_exit(char **map);
int			ft_check_border(char **map);
int			ft_spriteallowed(char c);
int			ft_close(t_program *program);
int			ft_input(int key, void *param);
int			ft_check_map_sprite(char **map);
int			ft_checksprite(char **map);
int			ft_check_map(char **map);
int			ft_check_map_dimension(char **map);
int			ft_compare_vect(t_vector v1, t_vector v2);
char		*ft_get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *str, int c );
char		**ft_cpymap(char **map);
char		**ft_takemap(char *path);
void		fill(char **tab, t_vector size, t_vector cur, char to_fill);
void		ft_flood_fill(char **tab, t_vector size, t_vector begin);
void		ft_createwall(t_program program);
void		ft_createfloor(t_program program);
void		ft_createedible(t_program program);
void		ft_door_check(t_program *program);
void		ft_put_move(int move, int pos, t_program *program);
void		ft_print_move(int move, t_program *program);
void		ft_load_map(t_program *program, char *path);
void		ft_enemy_move(t_program *program);
void		ft_check_end(t_program *program);
void		ft_createblack(t_program *program);
void		ft_destroy_char(t_program program);
void		ft_destroy(t_program program);
void		ft_end(t_program *program);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t c, size_t len);
void		ft_free_map(char **map);
void		ft_putstr(char *str);
void		ft_init_first(t_program *program);
void		ft_init_second(t_program *program);
void		ft_update_partial(t_program *program, int frame);
void		ft_enemies_part(t_program *program, int frame);
void		ft_put_move1(int move, int pos, t_program *program);
void		ft_put_move2(int move, int pos, t_program *program);
void		ft_input_core(t_program *program, int key);
t_vector	ft_take_mapsize(char **map);
t_vector	ft_add_vect_list(int y, int x);
t_vector	ft_take_pos(char **map, char elem);
t_vector	*ft_take_starting_dir(char **map, char check, char checked);
t_window	ft_new_window(void *mlx, int widht, int height, char *name);

#endif
