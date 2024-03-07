/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:55:59 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/20 14:44:10 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (data->map[y][x] != '1')
	{
		ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(data->moves + 1, 1);
		ft_putstr_fd("\n", 1);
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
