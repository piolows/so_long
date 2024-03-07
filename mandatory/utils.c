/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:03:31 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/16 14:09:35 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**arraydup(char **arr)
{
	char	**ret;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	while (arr[i[0]])
		i[0]++;
	ret = malloc(sizeof(char *) * (i[0] + 1));
	while (arr[i[1]])
	{
		ret[i[1]] = ft_strdup(arr[i[1]]);
		i[1]++;
	}
	ret[i[1]] = NULL;
	return (ret);
}

int	getfd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		errors(3, NULL, NULL);
	return (fd);
}

void	freearray(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_data	getmapsize(char **map, t_data win)
{
	win.wt = strlen_sl(map[0]) * 64;
	win.ht = 0;
	while (map[win.ht])
		win.ht++;
	win.ht *= 64;
	return (win);
}

void	argcheck(int ac, char **av)
{
	if (ac != 2)
		errors(1, NULL, NULL);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		errors(4, NULL, NULL);
}
