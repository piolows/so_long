/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:55:59 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/16 13:55:19 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	death(t_data *data)
{
	data->l = 0;
	data->tx.j = 0;
	putsingletile(data, data->px, data->py);
}

void	moveplayer(t_data *data, int x, int y)
{
	putsingletile(data, x, y);
	mlx_put_image_to_window
		(data->mlx, data->win, data->tx.p.img, x * 64, y * 64);
	putsingletile(data, data->px, data->py);
	data->px = x;
	data->py = y;
	puttext(data);
}

void	wasd(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'E')
	{
		if (data->c1 == 0)
			success(data);
		else
		{
			mlx_string_put(data->mlx, data->win, 8, 48, 0xffffff,
				"Collect the pawns!");
			return ;
		}
	}
	else if (data->map[y][x] == 'R' || data->map[y][x] == 'Q')
		death(data);
	else if (data->map[y][x] != '1')
	{
		if (data->map[y][x] == 'C')
			data->c1--;
		data->map[data->py][data->px] = '0';
		data->map[y][x] = 'P';
		data->moves++;
		moveplayer(data, x, y);
	}
}

void	move(int keysym, t_data *data)
{
	if (keysym == S_KEY)
		wasd(data, data->py + 1, data->px);
	else if (keysym == W_KEY)
		wasd(data, data->py - 1, data->px);
	else if (keysym == A_KEY)
		wasd(data, data->py, data->px - 1);
	else if (keysym == D_KEY)
		wasd(data, data->py, data->px + 1);
}
