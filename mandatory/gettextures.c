/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettextures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:51:49 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/19 21:23:13 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checktextures(t_data *data)
{
	if (!data->tx.p.img || !data->tx.f1.img || !data->tx.f2.img
		|| !data->tx.e.img || !data->tx.c1.img || !data->tx.w.img)
	{
		ft_putendl_fd
			("Error\nTexture(s) not found or couldn't be opened.", 2);
		destroyall(data, 1);
	}
}

void	gettextures2(t_data *data)
{
	data->tx.p.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.p.path, &data->tx.p.wt, &data->tx.p.ht);
	data->tx.w.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.w.path, &data->tx.w.wt, &data->tx.w.ht);
	data->tx.f1.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.f1.path, &data->tx.f1.wt, &data->tx.f1.ht);
	data->tx.f2.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.f2.path, &data->tx.f2.wt, &data->tx.f2.ht);
	data->tx.e.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.e.path, &data->tx.e.wt, &data->tx.e.ht);
	data->tx.c1.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.c1.path, &data->tx.c1.wt, &data->tx.c1.ht);
}

void	gettextures(t_data *data)
{
	data->tx.p.path = "textures/queen_1.xpm";
	data->tx.w.path = "textures/black_wall.xpm";
	data->tx.f1.path = "textures/white_brick.xpm";
	data->tx.f2.path = "textures/pink_brick.xpm";
	data->tx.e.path = "textures/king_1.xpm";
	data->tx.c1.path = "textures/pawn_1.xpm";
	gettextures2(data);
	checktextures(data);
}
