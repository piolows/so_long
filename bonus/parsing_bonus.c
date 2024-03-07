/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:02 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/21 14:46:37 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	checkwalls(char **map)
{
	int	i[3];

	i[0] = 0;
	i[1] = 1;
	i[2] = 0;
	while (map[i[2]])
		i[2]++;
	while (map[0][i[0]] && map[i[2] - 1][i[0]])
	{
		if (map[0][i[0]] != '1' || map[i[2] - 1][i[0]] != '1')
			errors(8, NULL, map);
		i[0]++;
	}
	i[0] = ft_strlen(map[0]);
	while (map[i[1]] && i[1] < i[2])
	{
		if (map[i[1]][0] != '1' || map[i[1]][i[0] - 1] != '1')
			errors(2, NULL, map);
		i[1]++;
	}
	if ((i[0] < 3 || i[2] < 5) && (i[0] < 5 || i[2] < 3))
		errors(2, NULL, map);
}

void	checkmapwidth(char **map_lines)
{
	int		len[2];
	int		i;

	i = 0;
	len[0] = strlen_sl(map_lines[i++]);
	while (map_lines[i])
	{
		len[1] = strlen_sl(map_lines[i]);
		if (len[0] != len[1])
			errors(7, NULL, map_lines);
		i++;
	}
}

void	checkmap(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr("01CEPRQ\n", map[i]))
			i++;
		else
			errors(6, map, NULL);
	}
}

char	*getmap(int fd)
{
	char	*str[3];

	str[0] = NULL;
	while (1)
	{
		str[1] = get_next_line(fd);
		if (str[1])
		{
			str[2] = str[0];
			str[0] = ft_strjoin(str[0], str[1]);
			if (str[2])
				free(str[2]);
			free(str[1]);
		}
		if (!str[1])
			break ;
	}
	if (!str[0])
		errors(10, NULL, NULL);
	return (str[0]);
}

void	getmaparray(char *file, t_data *data)
{
	char	*map;
	t_mcpy	mcpy;
	int		fd;
	int		valid;

	fd = getfd(file);
	map = getmap(fd);
	checkmap(map);
	close(fd);
	data->map = split_sl(map, '\n');
	free(map);
	checkmapwidth(data->map);
	checkwalls(data->map);
	countchars(data, 0, 0, 0);
	mcpy.map = arraydup(data->map);
	mcpy.er = 0;
	data->c2 = data->c1;
	valid = pathcheck(&mcpy, data->px, data->py, &data->c2);
	freearray(mcpy.map);
	if (valid == 0)
		errors(2, NULL, data->map);
}
