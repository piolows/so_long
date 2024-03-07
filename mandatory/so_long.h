/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:49:45 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/20 15:13:06 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../GNL/get_next_line_bonus.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# ifdef __APPLE__
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define UP 126
#  define LEFT 123
#  define DOWN 125
#  define RIGHT 124
#  define ESC 53
# else
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define UP 65362
#  define LEFT 65361
#  define DOWN 65364
#  define RIGHT 65363
#  define ESC 65307
# endif

typedef struct s_placements
{
	int	x;
	int	y;
	int	i;
	int	j;
}	t_placements;

typedef struct s_mcpy
{
	char	**map;
	int		er;
}	t_mcpy;

typedef struct s_xpmimg
{
	void	*img;
	char	*path;
	int		ht;
	int		wt;
}	t_xpmimg;

typedef struct s_tx
{
	t_xpmimg	p;
	t_xpmimg	e;
	t_xpmimg	c1;
	t_xpmimg	c2;
	t_xpmimg	c3;
	t_xpmimg	c4;
	t_xpmimg	w;
	t_xpmimg	f1;
	t_xpmimg	f2;
	t_xpmimg	f3;
	t_xpmimg	r;
	t_xpmimg	r2;
	t_xpmimg	f;
	t_xpmimg	q;
	t_xpmimg	s;
	t_xpmimg	h;
	int			i;
	int			j;
}	t_tx;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		wt;
	int		ht;
	char	**map;
	int		px;
	int		py;
	int		moves;
	int		er;
	int		c1;
	int		c2;
	int		l;
	t_tx	tx;
}	t_data;

void		argcheck(int ac, char **av);
void		freearray(char **arr);
void		errors(int n, char *str, char **arr);
void		checkmap(char *map);
char		**split_sl(char const *s, char c);
size_t		strlen_sl(const char *str);
int			getfd(char *file);
char		*getmap(int fd);
t_data		getmapsize(char **map, t_data win);
void		getmaparray(char *file, t_data *data);
void		gettextures(t_data *data);
void		putmap(t_data *data, t_tx tx);
void		putactors(t_data *data, t_tx tx);
void		destroyall(t_data *data, int e);
void		destroytextures(t_data *data);
void		move(int keysym, t_data *data);
void		countchars(t_data *data, int p, int e);
char		**arraydup(char **arr);
int			pathcheck(t_mcpy *mcpy, int x, int y, int *collectibles);
void		success(t_data *data);
void		f1f2(t_data *data, t_tx tx, int x, int y);
void		f2f1(t_data *data, t_tx tx, int x, int y);
void		puttext(t_data *data);
int			loops(t_data *data);
void		putsingletile(t_data *data, int x, int y);
void		movequeen(t_data *data, t_placements *p);
void		attack(t_data *data, int keysym);
void		destroytextures(t_data *data);
void		puttiles(t_data *data, int x, int y, int t);
void		putrook(t_data *data, t_placements *p);

#endif