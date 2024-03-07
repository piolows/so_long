/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroytextures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:54:16 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/19 21:23:33 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroytextures(t_data *data)
{
	if (data->tx.p.img)
		mlx_destroy_image(data->mlx, data->tx.p.img);
	if (data->tx.w.img)
		mlx_destroy_image(data->mlx, data->tx.w.img);
	if (data->tx.c1.img)
		mlx_destroy_image(data->mlx, data->tx.c1.img);
	if (data->tx.f2.img)
		mlx_destroy_image(data->mlx, data->tx.f2.img);
	if (data->tx.f1.img)
		mlx_destroy_image(data->mlx, data->tx.f1.img);
	if (data->tx.e.img)
		mlx_destroy_image(data->mlx, data->tx.e.img);
}
