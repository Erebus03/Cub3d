#include <stdio.h>
#include <unistd.h>
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>

typedef struct	s_minmap
{
	char	position;
	int		square_size;
	int		width_percent;
	int		player_size;
}	t_minmap;

typedef struct	s_cub
{
	void		*mlx;
	void		*win;
	char		**map;
	t_minmap	minmap;
}	t_cub;

int		key_press(int key, t_cub *c);
void	exitcub(t_cub *c);
void	verr(char *msg);
void	exiterr(char *msg);
void	run(t_cub *c);
void	parse(t_cub *c);
void	init(t_cub *c);
void	draw_map(t_cub *c);
void	draw_minimap(t_cub *c);
size_t	ft_strlen(char *s);