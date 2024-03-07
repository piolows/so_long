/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attacking.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:54:10 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/16 13:54:27 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	putfire(t_data *data, int y, int x)
{
	if (data->map[y][x] != '1' && data->map[y][x] != 'E'
	&& data->map[y][x] != 'C')
	{
		data->tx.j = 0;
		if (data->map[y][x] == 'C')
			data->c1--;
		data->map[y][x] = 'F';
		mlx_put_image_to_window
		(data->mlx, data->win, data->tx.f.img, x * 64, y * 64);
		puttext(data);
	}
}

void	attack(t_data *data, int keysym)
{
	if (keysym == UP)
		putfire(data, data->py - 1, data->px);
	else if (keysym == LEFT)
		putfire(data, data->py, data->px - 1);
	else if (keysym == DOWN)
		putfire(data, data->py + 1, data->px);
	else if (keysym == RIGHT)
		putfire(data, data->py, data->px + 1);
}
