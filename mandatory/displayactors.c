/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayactors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:05:42 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/19 20:25:26 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putsingletile(t_data *data, int x, int y)
{
	if (y % 2 == 0)
		f1f2(data, data->tx, x * 64, y * 64);
	else
		f2f1(data, data->tx, x * 64, y * 64);
}

void	putactors2(t_data *data, t_tx tx, int *xy, int actor)
{
	if (actor == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, tx.p.img, xy[0], xy[1]);
		data->px = xy[0] / 64;
		data->py = xy[1] / 64;
	}
	if (actor == '1')
		mlx_put_image_to_window(data->mlx, data->win, tx.w.img, xy[0], xy[1]);
	if (actor == 'C')
		mlx_put_image_to_window(data->mlx, data->win, tx.c1.img, xy[0], xy[1]);
	if (actor == 'E')
		mlx_put_image_to_window(data->mlx, data->win, tx.e.img, xy[0], xy[1]);
}

void	putactors(t_data *data, t_tx tx)
{
	int	i[2];
	int	xy[2];

	i[0] = 0;
	i[1] = 0;
	xy[0] = 0;
	xy[1] = 0;
	while (data->map[i[0]])
	{
		while (data->map[i[0]][i[1]])
		{
			putactors2(data, tx, xy, data->map[i[0]][i[1]]);
			xy[0] += 64;
			i[1]++;
		}
		xy[0] = 0;
		i[1] = 0;
		xy[1] += 64;
		i[0]++;
	}
}
