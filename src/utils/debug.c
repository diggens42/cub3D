/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:59:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/24 18:33:28 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	debug_player(t_player *player)
{
	if (player->pos.x > 0 && player->pos.y > 0)
		printf("Player Pos	X: %f	Y: %f\n", player->pos.x, player->pos.y);
	else
		printf("Player Pos missing");
	if (player->dir)
		printf("Player Dir	%f\n", player->dir);
	else
		printf("Player Dir missing");
}

static void	debug_map(t_map *map)
{
	int	y;

	printf("Floor   color: %d\n", map->floor);
	printf("Ceiling color: %d\n", map->ceiling);
	printf("\n");
	if (map->wall[0] != NULL)
		printf("North wall texture loaded\n");
	if (map->wall[1] != NULL)
		printf("East  wall texture loaded\n");
	if (map->wall[2] != NULL)
		printf("South wall texture loaded\n");
	if (map->wall[3] != NULL)
		printf("West  wall texture loaded\n");
	if (map->door[0] != NULL)
		printf("Door closed texture loaded\n");
	if (map->door[1] != NULL)
		printf("Door open   texture loaded\n");
	printf("\n");
	printf("Mapsize		X: %f	Y: %f\n", map->max.x, map->max.y);
	printf("\n");
	y = 0;
	while (y <= map->max.y)
	{
		if (y < 10)
			printf("map_line[0%d]: %s\n", y, map->map[y]);
		else
			printf("map_line[%d]: %s\n", y, map->map[y]);
		y++;
	}
}

void	debug_parse(t_game *game)
{
	debug_map(game->map);
	debug_player(game->player);
}
