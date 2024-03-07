/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroytextures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:54:16 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/16 13:54:16 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroytextures2(t_data *data)
{
	if (data->tx.q.img)
		mlx_destroy_image(data->mlx, data->tx.q.img);
	if (data->tx.r2.img)
		mlx_destroy_image(data->mlx, data->tx.r2.img);
	if (data->tx.s.img)
		mlx_destroy_image(data->mlx, data->tx.s.img);
	if (data->tx.h.img)
		mlx_destroy_image(data->mlx, data->tx.h.img);
	if (data->tx.f3.img)
		mlx_destroy_image(data->mlx, data->tx.f3.img);
}

void	destroytextures(t_data *data)
{
	if (data->tx.p.img)
		mlx_destroy_image(data->mlx, data->tx.p.img);
	if (data->tx.w.img)
		mlx_destroy_image(data->mlx, data->tx.w.img);
	if (data->tx.c1.img)
		mlx_destroy_image(data->mlx, data->tx.c1.img);
	if (data->tx.c2.img)
		mlx_destroy_image(data->mlx, data->tx.c2.img);
	if (data->tx.c3.img)
		mlx_destroy_image(data->mlx, data->tx.c3.img);
	if (data->tx.c4.img)
		mlx_destroy_image(data->mlx, data->tx.c4.img);
	if (data->tx.f2.img)
		mlx_destroy_image(data->mlx, data->tx.f2.img);
	if (data->tx.f1.img)
		mlx_destroy_image(data->mlx, data->tx.f1.img);
	if (data->tx.e.img)
		mlx_destroy_image(data->mlx, data->tx.e.img);
	if (data->tx.r.img)
		mlx_destroy_image(data->mlx, data->tx.r.img);
	if (data->tx.f.img)
		mlx_destroy_image(data->mlx, data->tx.f.img);
	destroytextures2(data);
}
