/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:34:53 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/23 17:45:17 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	putpawn2(t_data *data, t_placements *p)
{
	if (data->tx.i % 50 == 0 || data->tx.i % 150 == 0)
	{
		putsingletile(data, p->x / 64, p->y / 64);
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.c1.img, p->x, p->y);
	}
	if (data->tx.i % 100 == 0)
	{
		putsingletile(data, p->x / 64, p->y / 64);
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.c2.img, p->x, p->y);
	}
	if (data->tx.i % 200 == 0)
	{
		putsingletile(data, p->x / 64, p->y / 64);
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.c3.img, p->x, p->y);
	}
}

void	putpawn(t_data *data, t_placements *p)
{
	if (data->map[p->i + 1][p->j] == 'P'
	|| data->map[p->i - 1][p->j] == 'P'
	|| data->map[p->i][p->j + 1] == 'P'
	|| data->map[p->i][p->j - 1] == 'P')
	{
		putsingletile(data, p->x / 64, p->y / 64);
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.c4.img, p->x, p->y);
	}
	else
		putpawn2(data, p);
}

void	putactorsloop(t_data *data, t_placements *p)
{
	while (data->map[p->i])
	{
		while (data->map[p->i][p->j])
		{
			if (data->map[p->i][p->j] == 'C')
				putpawn(data, p);
			if (data->map[p->i][p->j] == 'R')
				putrook(data, p);
			if (data->map[p->i][p->j] == 'Q')
				movequeen(data, p);
			if (data->map[p->i][p->j] == 'E')
				mlx_put_image_to_window
				(data->mlx, data->win, data->tx.e.img, p->x, p->y);
			if (data->map[p->i][p->j] == 'F' && data->tx.j == 15)
				putsingletile(data, p->j, p->i);
			p->x += 64;
			p->j++;
		}
		p->x = 0;
		p->j = 0;
		p->y += 64;
		p->i++;
	}
}

void	checkstate(t_data *data)
{
	if (data->l == 0)
	{
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.s.img, data->px * 64, data->py * 64);
		mlx_string_put
		(data->mlx, data->win, data->wt / 2 - 52, data->ht / 2,
		0xffffff, "You've been kiled!");
	}
	if (data->l == 2)
	{
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.e.img,
		data->wt / 2 - 64, data->ht / 2 - 32);
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.p.img,
		data->wt / 2, data->ht / 2 - 32);
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.h.img,
		data->wt / 2 - 32, data->ht / 2 - 32);
		mlx_string_put
		(data->mlx, data->win, data->wt / 2 - 56,
		data->ht / 2 - 64, 0xffffff, "You saved the king!");
	}
}

int	loops(t_data *data)
{
	t_placements	p;

	p.i = 0;
	p.j = 0;
	p.x = 0;
	p.y = 0;
	data->tx.i++;
	data->tx.j++;
	if (data->l != 2)
		putactorsloop(data, &p);
	checkstate(data);
	if (data->tx.i == 12000)
		data->tx.i = 0;
	if (data->tx.j == 200 && data->l == 2)
		destroyall(data, 0);
	if (data->tx.j == 200 && data->l == 0)
		destroyall(data, 0);
	if (data->tx.j == 36000)
		data->tx.j = 0;
	return (0);
}
