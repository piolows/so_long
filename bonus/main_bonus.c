/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:19:44 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/20 15:12:41 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long_bonus.h"

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
	data->l = 2;
	data->tx.j = 0;
	puttiles(data, 0, 0, 1);
	ft_putstr_fd("Level completed!\nYou moved ", 1);
	ft_putnbr_fd(data->moves + 1, 1);
	ft_putstr_fd(" time(s).\n", 1);
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
			|| keysym == D_KEY) && data->l == 1)
		move(keysym, data);
	if ((keysym == UP || keysym == DOWN
			|| keysym == LEFT || keysym == RIGHT) && data->l == 1)
		attack(data, keysym);
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
	data.tx.i = 0;
	data.tx.j = 0;
	data.l = 1;
	putmap(&data, data.tx);
	mlx_hook(data.win, 2, 1L << 0, &on_keypress, &data);
	mlx_hook(data.win, 17, 1L << 2, &exitbutton, &data);
	mlx_loop_hook(data.mlx, loops, &data);
	mlx_loop(data.mlx);
}
