#include <stdio.h>
#include <unistd.h>
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>

typedef struct s_cub
{
    char	**map;
    void	*mlx;
    void	*win;
}	t_cub;

int		key_press(int key, t_cub *c);
void	exitcub(t_cub *c);
void	verr(char *msg);
void	exiterr(char *msg);
void	run(t_cub *c);
void	parse(t_cub *c);
void	init(t_cub *c);
