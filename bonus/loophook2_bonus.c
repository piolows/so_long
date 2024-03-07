/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:46:20 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/23 17:35:36 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	putrook(t_data *data, t_placements *p)
{
	if (data->tx.i % 50 == 0 || data->tx.i % 150 == 0)
	{
		putsingletile(data, p->x / 64, p->y / 64);
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.r2.img, p->x, p->y);
	}
	if (data->tx.i % 100 == 0)
	{
		putsingletile(data, p->x / 64, p->y / 64);
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.r.img, p->x, p->y);
	}
}

void	putqueen(t_data *data, t_placements *p, int x, int y)
{
	if (data->map[y][x] == 'P')
	{
		data->l = 0;
		data->tx.j = 0;
		putsingletile(data, p->x / 64, p->y / 64);
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.q.img, x * 64, y * 64);
	}
	data->map[p->y / 64][p->x / 64] = '0';
	data->map[y][x] = 'Q';
	putsingletile(data, p->x / 64, p->y / 64);
	mlx_put_image_to_window
	(data->mlx, data->win, data->tx.q.img, x * 64, y * 64);
}

int	checkqueen(t_data *data, int x, int y)
{
	if ((data->map[y + 1][x] == '1' || data->map[y + 1][x] == 'R'
	|| data->map[y + 1][x] == 'C' || data->map[y + 1][x] == 'E')
	&& (data->map[y - 1][x] == '1' || data->map[y - 1][x] == 'R'
	|| data->map[y - 1][x] == 'C' || data->map[y - 1][x] == 'E')
	&& (data->map[y][x + 1] == '1' || data->map[y][x + 1] == 'R'
	|| data->map[y][x + 1] == 'C' || data->map[y][x + 1] == 'E')
	&& (data->map[y][x - 1] == '1' || data->map[y][x - 1] == 'R'
	|| data->map[y][x - 1] == 'C' || data->map[y][x - 1] == 'E'))
		return (0);
	return (1);
}

void	randomize(t_data *data, t_placements *p, int x, int y)
{
	int	ran;
	int	x2;
	int	y2;

	if (checkqueen(data, x, y) == 0)
		return ;
	ran = rand() % 4 + 1;
	x2 = x;
	y2 = y;
	if (ran == 1)
		x += 1;
	if (ran == 2)
		x -= 1;
	if (ran == 3)
		y += 1;
	if (ran == 4)
		y -= 1;
	if (data->map[y][x] != '1' && data->map[y][x] != 'R'
	&& data->map[y][x] != 'C' && data->map[y][x] != 'E')
		putqueen(data, p, x, y);
	else
		randomize(data, p, x2, y2);
}

void	movequeen(t_data *data, t_placements *p)
{
	int	x;
	int	y;

	if (data->tx.i % 30 == 0)
	{
		x = p->x / 64;
		y = p->y / 64;
		data->tx.i++;
		randomize(data, p, x, y);
	}
}
