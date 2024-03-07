/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:19:44 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/19 20:22:47 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	destroyall(t_data *data, int e)
{
	if (data->map)
		freearray(data->map);
	destroytextures(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	exit(e);
}

void	success(t_data *data)
{
	ft_putstr_fd("Level completed!\nYou moved ", 1);
	ft_putnbr_fd(data->moves + 1, 1);
	ft_putstr_fd(" time(s).\n", 1);
	destroyall(data, 0);
}

int	exitbutton(t_data *data)
{
	ft_putendl_fd("Game exited.", 1);
	destroyall(data, 0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if ((keysym == W_KEY || keysym == A_KEY || keysym == S_KEY
			|| keysym == D_KEY))
		move(keysym, data);
	if (keysym == ESC)
	{
		ft_putendl_fd("Game exited.", 1);
		destroyall(data, 0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	argcheck(ac, av);
	data.mlx = mlx_init();
	getmaparray(av[1], &data);
	data = getmapsize(data.map, data);
	data.win = mlx_new_window(data.mlx, data.wt, data.ht, "So Long!");
	gettextures(&data);
	data.moves = 0;
	putmap(&data, data.tx);
	mlx_hook(data.win, 2, 1L << 0, &on_keypress, &data);
	mlx_hook(data.win, 17, 1L << 2, &exitbutton, &data);
	mlx_loop(data.mlx);
}
