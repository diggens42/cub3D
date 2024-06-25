/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:55 by mott              #+#    #+#             */
/*   Updated: 2024/06/25 18:45:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>		// open
# include <unistd.h>	// close, read, write
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit
# include <string.h>	// strerror
# include <stdbool.h>
# include <stdint.h>
# include <math.h>
# include "../libft/libft.h"
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define BLACK			0x000000FF	// (0, 0, 0, 255)
# define WHITE			0xFFFFFFFF	// (255, 255, 255, 255)
# define WHITE_SMOKE	0xF5F5F5FF	// (245, 245, 245, 255)
# define RED			0xFF0000FF	// (255, 0, 0, 255)
# define LIME			0x00FF00FF	// (0, 255, 0, 255)
# define BLUE			0x0000FFFF	// (0, 0, 255, 255)
# define YELLOW			0xFFFF00FF	// (255, 255, 0, 255)
# define CYAN			0x00FFFFFF	// (0, 255, 255, 255)
# define MAGENTA		0xFF00FFFF	// (255, 0, 255, 255)
# define SILVER			0xC0C0C0FF	// (192, 192, 192, 255)
# define GRAY			0x808080FF	// (128, 128, 128, 255)
# define MAROON			0x800000FF	// (128, 0, 0, 255)
# define OLIVE			0x808000FF	// (128, 128, 0, 255)
# define GREEN			0x008000FF	// (0, 128, 0, 255)
# define PURPLE			0x800080FF	// (128, 0, 128, 255)
# define TEAL			0x008080FF	// (0, 128, 128, 255)
# define NAVY			0x000080FF	// (0, 0, 128, 255)

# define WIDTH			1920
# define HEIGHT			1080
# define F_SIZE			32
# define P_SIZE			5
# define FOV			60.0
# define ONE_PI			3.141592
# define TWO_PI			6.283185
# define HALF_PI		1.570796
# define THREE_HALF_PI	4.712388
# define EAST			0
# define NORTH			1
# define WEST			2
# define SOUTH			3
# define MOVE_SPEED		1.75
# define ROTATION_SPEED	0.034907

typedef struct s_coords
{
	double	x;
	double	y;
}	t_coords;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_window;

typedef struct s_map
{
	char			**map;
	t_coords		max;
	int				floor;
	int				ceiling;
	mlx_texture_t	*wall[4];
	mlx_texture_t	*door[2];
}	t_map;

typedef struct s_player
{
	t_coords	pos;
	double		dir;
}	t_player;

typedef struct s_parse
{
	bool		walls;
	bool		doors;
	bool		floor_ceiling;
	bool		map;
	bool		player;
}	t_parse;

typedef struct s_ray
{
	t_coords	hit[WIDTH];
	double		len[WIDTH];
	int			dir[WIDTH]; //wall
	double		fov_start;
	double		fov_add;
}	t_ray;

typedef struct s_texture
{
	t_coords	pos;
	double		y_scale;
	double		y_offset;
	int			wall_height;
	int			wall_offset;
}	t_texture;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_parse		*parsed;
	t_ray		*ray;
	bool		recalculate;
	bool		minimap;
	bool		mouse_rotate;
}	t_game;

// main.c
int		main(int argc, char **argv);

// engine
// draw_game.c
void	draw_background(t_game *game);
void	draw_wall(t_game *game, double radian, int x);

// draw_minimap.c
void	draw_minimap(t_game *game);

// init.c
int		get_rgba(int r, int g, int b, int a);
double	pi_overflow(double radian);
void	init_game(t_game *game);
void	loop_hook(void *param);

// key.c
// void	key_hook(mlx_key_data_t keydata, void *param);
void	key_hook(void *param);
void	minimap(mlx_key_data_t keydata, void *param);
void	rotate_player(t_game *game, char dir);

// mouse.c
void	mouse_hook(t_game *game);

// ray.c
void	ray_calculation(t_game *game, double radian, int x);

// parser
// parsing
void	init_map(t_game *game, char *filename);
void	parse_tex(t_game *game, char *line);
void	parse_floor_ceiling(t_game *game, char *line);
void	parse_mapfile(t_game *game, char *filename);

// utils
// error.c
void	ft_error(t_game *game, const char *errormsg);

//free.c
void	free_game(t_game *game);

// bools.c
bool	is_map_char(char c);
bool	is_map_line(char *line);
bool	is_player_char(char c);
bool	is_player_start(char *line);

// debug.c
void	debug_parse(t_game *game);

#endif
