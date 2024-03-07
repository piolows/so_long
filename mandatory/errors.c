/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:19:46 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/24 17:39:39 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(int n, char *str, char **arr)
{
	if (n == 1)
		ft_putendl_fd("Error\nInvalid arguments. ./so_long (map name)", 2);
	if (n == 2)
		ft_putendl_fd("Error\nMap has no valid path.", 2);
	if (n == 3)
		ft_putendl_fd("Error\nMap couldn't be opened or doesn't exist.", 2);
	if (n == 4)
		ft_putendl_fd("Error\nMap must be a \".ber\" file.", 2);
	if (n == 5)
		ft_putendl_fd("Error\nMap contains duplicate/missing characters.", 2);
	if (n == 6)
		ft_putendl_fd("Error\nMap contains invalid characters.", 2);
	if (n == 7)
		ft_putendl_fd("Error\nMap width is invalid.", 2);
	if (n == 8)
		ft_putendl_fd("Error\nMap is not surrounded by walls.", 2);
	if (n == 9)
		ft_putendl_fd("Error\nMap has no collectibles.", 2);
	if (n == 10)
		ft_putendl_fd("Error\nMap is empty.", 2);
	if (str)
		free(str);
	if (arr)
		freearray(arr);
	exit(1);
}
