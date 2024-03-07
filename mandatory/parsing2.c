/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:34:41 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/19 20:26:58 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pathcheck(t_mcpy *mcpy, int x, int y, int *collectibles)
{
	if (mcpy->map[y][x] == '1' || mcpy->map[y][x] == 'V')
		return (0);
	if (mcpy->map[y][x] == 'E')
	{
		mcpy->er = 1;
		return (*collectibles == 0);
	}
	if (mcpy->map[y][x] == 'C')
		(*collectibles)--;
	mcpy->map[y][x] = 'V';
	if (pathcheck(mcpy, x, y - 1, collectibles))
		return (1);
	if (pathcheck(mcpy, x - 1, y, collectibles))
		return (1);
	if (pathcheck(mcpy, x + 1, y, collectibles))
		return (1);
	if (pathcheck(mcpy, x, y + 1, collectibles))
		return (1);
	mcpy->map[y][x] = '0';
	return ((*collectibles == 0) * (mcpy->er == 1));
}

void	countchars2(t_data *data, int p, int e)
{
	if (p != 1 || e != 1)
		errors(5, NULL, data->map);
	if (data->c1 == 0)
		errors(9, NULL, data->map);
}

void	countchars(t_data *data, int p, int e)
{
	int	i[2];

	i[0] = -1;
	data->c1 = 0;
	while (data->map[++i[0]])
	{
		i[1] = 0;
		while (data->map[i[0]][i[1]])
		{
			if (data->map[i[0]][i[1]] == 'C')
				data->c1++;
			else if (data->map[i[0]][i[1]] == 'P')
			{
				data->px = i[1];
				data->py = i[0];
				p++;
			}
			else if (data->map[i[0]][i[1]] == 'E')
				e++;
			i[1]++;
		}
	}
	countchars2(data, p, e);
}
