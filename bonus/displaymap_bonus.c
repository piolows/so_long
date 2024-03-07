/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaymap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:03:34 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/14 13:27:36 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	puttext(t_data *data)
{
	char	*moves;
	char	*col;

	moves = ft_itoa(data->moves);
	col = ft_itoa(data->c1);
	mlx_put_image_to_window(data->mlx, data->win, data->tx.w.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->tx.w.img, 64, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->tx.w.img, 128, 0);
	mlx_string_put(data->mlx, data->win, 8, 16, 0xffffff, "Moves made: ");
	mlx_string_put(data->mlx, data->win, 136, 16, 0xffffff, moves);
	mlx_string_put(data->mlx, data->win, 8, 32, 0xffffff, "Pawns left: ");
	mlx_string_put(data->mlx, data->win, 136, 32, 0xffffff, col);
	free(moves);
	free(col);
}

void	f2f1(t_data *data, t_tx tx, int x, int y)
{
	if ((x / 64) % 2 == 0)
		mlx_put_image_to_window(data->mlx, data->win, tx.f2.img, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win, tx.f1.img, x, y);
}

void	f1f2(t_data *data, t_tx tx, int x, int y)
{
	if ((x / 64) % 2 == 0)
		mlx_put_image_to_window(data->mlx, data->win, tx.f1.img, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win, tx.f2.img, x, y);
}

void	puttiles(t_data *data, int x, int y, int t)
{
	while (y < data->ht)
	{
		while (x < data->wt)
		{
			if (t == 0)
				putsingletile(data, x / 64, y / 64);
			if (t == 1)
				mlx_put_image_to_window
				(data->mlx, data->win, data->tx.f3.img, x, y);
			x += 64;
		}
		x = 0;
		y += 64;
	}
}

void	putmap(t_data *data, t_tx tx)
{
	puttiles(data, 0, 0, 0);
	putactors(data, tx);
	puttext(data);
}
