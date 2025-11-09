/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:39:33 by zzin              #+#    #+#             */
/*   Updated: 2025/11/09 21:24:45 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"

int	inword(char *word, char c)
{
	int i = 0;

	while (word[i])
	{
		if(word[i] == c)
			return 1;
		i++;
	}
	return 0;
}

void	*prmap(char **map)
{
	//void	*p;
	if(!map || !*map || !**map)
	{
		printf("empty\n");
		return NULL;
	}
	int a = 0;
	int c;
	int p = 0;
	while(map[a])
	{
		c = 0;
		while (map[a][c])
		{
			if(map[a][c] == 'N')
				p = 1;
			write(1, " ", 1);
			write(1, &map[a][c], 1);
			c++;
		}
		if(p)
		{
			write(1, " <", 2);
			p = 0;
		}
		write(1, "\n", 1);
		a++;
	}
	write(1, "---------------\n", 16);
	return p;
}

void	draw_minimap(t_cub *c)
{
	if(c->rcast->mlx)
		return ;
	int x = 0;
	int y = 0;

	while (x <= 1920)
	{
		y = 0;
		while(y <= 1080)
		{
			y++;
		}
		x++;
	}
	
}

int	close_window(t_cub	*c)
{
	mlx_destroy_window(c->rcast->mlx, c->rcast->win);
	mlx_destroy_display(c->rcast->mlx);
	free(c->rcast->mlx);
	clear_heap();
    exit(0);
    return 0;
}

int update(t_cub *c)
{
    if (c->key_w) printf("w\n");
    //if (c->key_s) c->py += speed;
    //if (c->key_a) c->px -= speed;
    //if (c->key_d) c->px += speed;

    //clear_image(c);          // wipe old frame
    //drawplayer(c);           // draw player into image
    //mlx_put_image_to_window(c->mlx, c->win, c->img, 0, 0); // display whole frame
    return (0);
}

int key_press(int key, t_cub *c)
{
    if (key == XK_Escape) // ESC
        return close_window(c);
    if (key == XK_w) c->key_w = 1;
    return (0);
}

int key_release(int key, t_cub *c)
{
    if (key == XK_w) c->key_w = 0;
    return (0);
}

void	init_mlx(t_cub *c)
{
	void	*m;

	m = mlx_init();
	if(!m)
		return ;
	c->rcast->mlx = m;
	c->rcast->win = mlx_new_window(m, 1920, 1080, "cubzz");
	if(!c->rcast->win)
		return ;
	mlx_hook(c->rcast->win, 2, 1L<<0, key_press, c);
	mlx_hook(c->rcast->win, 3, 1L<<1, key_release, c);
	mlx_hook(c->rcast->win, 17, 0, close_window, c);
	mlx_loop_hook(c->rcast->mlx, update, c);
	draw_minimap(c);
	mlx_loop(c->rcast->mlx);
}

void	init_cub(void)
{
	if(!cubs || cubs->rcast)
		return ;
	prmap(cubs->map);
	cubs->rcast = save(sizeof(t_rcast));
	cubs->key_w = 0;
	cubs->key_s = 0;
	cubs->key_a = 0;
	cubs->key_d = 0;
	init_mlx(cubs);
	return ;
}
