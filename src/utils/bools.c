/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:41:35 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/02 17:48:28 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

#ifdef BONUS

bool	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'D' || c == 'd'
		|| c == 'P' || is_player_char(c));
}

#else

bool	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_player_char(c));
}

#endif

bool	is_map_line(char *line)
{
	int	i;
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (ft_isspace(line[j]))
			j++;
		else
			break ;
	}
	if (line[j] == '\0')
		return (false);
	i = 0;
	while (line[i] != '\0')
	{
		if (!is_map_char(line[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_player_char(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

bool	is_player(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && is_map_line(line))
	{
		if (is_player_char(line[i]))
			return (true);
		i++;
	}
	return (false);
}
