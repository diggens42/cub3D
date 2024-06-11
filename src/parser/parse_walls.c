/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:52:17 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/11 17:00:34 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static mlx_texture_t	*set_texture(t_game *game, char *line)
{
	char			*filepath;
	mlx_texture_t	*texture;
	int				i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isspace(line[i]))
			i++;
		else if (line[i] == '.')
			break ;
		else
			ft_error(game, "parse_texture error - invalid filepath");
	}
	filepath = ft_strdup(line + i);
	texture = mlx_load_png(filepath);
	if (texture == NULL)
		ft_error(game, "parse_texture error - invalid file");
	free(filepath);
	return (texture);
}

void	parse_textures(t_game *game, char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		game->map->walls[0] = set_texture(game, &line[i + 2]);
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		game->map->walls[1] = set_texture(game, &line[i + 2]);
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		game->map->walls[2] = set_texture(game, &line[i + 2]);
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		game->map->walls[3] = set_texture(game, &line[i + 2]);
}
