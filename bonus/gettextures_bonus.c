/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettextures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:51:49 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/16 14:01:28 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	checktextures(t_data *data)
{
	if (!data->tx.p.img || !data->tx.f1.img || !data->tx.f2.img
		|| !data->tx.e.img || !data->tx.c1.img || !data->tx.c2.img
		|| !data->tx.c3.img || !data->tx.c4.img || !data->tx.w.img
		|| !data->tx.r.img || !data->tx.f.img || !data->tx.q.img
		|| !data->tx.r2.img || !data->tx.s.img || !data->tx.h.img
		|| !data->tx.f3.img)
	{
		ft_putendl_fd
			("Error\nTexture(s) not found or couldn't be opened.", 2);
		destroyall(data, 1);
	}
}

void	gettextures3(t_data *data)
{
	data->tx.r2.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.r2.path, &data->tx.r2.wt, &data->tx.r2.ht);
	data->tx.s.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.s.path, &data->tx.s.wt, &data->tx.s.ht);
	data->tx.h.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.h.path, &data->tx.h.wt, &data->tx.h.ht);
	data->tx.f3.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.f3.path, &data->tx.f3.wt, &data->tx.f3.ht);
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
	data->tx.c2.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.c2.path, &data->tx.c2.wt, &data->tx.c2.ht);
	data->tx.c3.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.c3.path, &data->tx.c3.wt, &data->tx.c3.ht);
	data->tx.c4.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.c4.path, &data->tx.c4.wt, &data->tx.c4.ht);
	data->tx.r.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.r.path, &data->tx.r.wt, &data->tx.r.ht);
	data->tx.f.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.f.path, &data->tx.f.wt, &data->tx.f.ht);
	data->tx.q.img = mlx_xpm_file_to_image
		(data->mlx, data->tx.q.path, &data->tx.q.wt, &data->tx.q.ht);
}

void	gettextures(t_data *data)
{
	data->tx.p.path = "textures/queen_1.xpm";
	data->tx.w.path = "textures/black_wall.xpm";
	data->tx.f1.path = "textures/white_brick.xpm";
	data->tx.f2.path = "textures/pink_brick.xpm";
	data->tx.e.path = "textures/king_1.xpm";
	data->tx.c1.path = "textures/pawn_1.xpm";
	data->tx.c2.path = "textures/pawn_2.xpm";
	data->tx.c3.path = "textures/pawn_3.xpm";
	data->tx.c4.path = "textures/pawn_4.xpm";
	data->tx.r.path = "textures/rook.xpm";
	data->tx.r2.path = "textures/rook2.xpm";
	data->tx.f.path = "textures/fire.xpm";
	data->tx.q.path = "textures/enemy_queen.xpm";
	data->tx.s.path = "textures/skull.xpm";
	data->tx.h.path = "textures/heart.xpm";
	data->tx.f3.path = "textures/blue_brick.xpm";
	gettextures2(data);
	gettextures3(data);
	checktextures(data);
}
