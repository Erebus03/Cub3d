/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:39:33 by zzin              #+#    #+#             */
/*   Updated: 2025/11/12 18:09:47 by zzin             ###   ########.fr       */
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

void	square(t_rcast *r, int x, int y, int color)
{
	int lx = x;
	int ly = y;

	int w = 0;
	int h = 0;
	while (w <= r->sq_size)
	{
		ly = y;
		h = 0;
		while (h <= r->sq_size)
		{
			mlx_pixel_put(r->mlx, r->win, lx, ly, color);
			ly++;
			h++;
		}
		lx++;
		w++;
	}
	
}

void	spawn_player(t_cub *c, int x, int y)
{
	c->rcast->psquarex = x;
	c->rcast->psquarey = y;
	c->rcast->px = x + ((c->rcast->sq_size - c->rcast->psize) / 2);
	c->rcast->py = y + ((c->rcast->sq_size - c->rcast->psize) / 2);
	c->rcast->fx = 0;
	c->rcast->fy = 0;
}

void	draw_player(t_cub *c)
{
	int lx = c->rcast->px;
	int ly = c->rcast->py;
	int w = 0;
	int h = 0;
	while (w <= c->rcast->psize)
	{
		ly = c->rcast->py;
		h = 0;
		while (h <= c->rcast->psize)
		{
			mlx_pixel_put(c->rcast->mlx, c->rcast->win, lx, ly, 0xff8800);
			ly++;
			h++;
		}
		lx++;
		w++;
	}
}

void	draw_minimap(t_cub *c)
{
	if(!c->rcast->mlx)
		return ;

	int	squares = c->mheight * c->mwidth;
	//int	mspace = 10;
	//int	eachsize = 30;
	c->rcast->sq_size = 30;
	c->rcast->psize = c->rcast->sq_size / 2;
	//int minmap_w = 100;
	//int minmap_h = ;
	//int	x = 0;
	//int	y = 0;
	//printf("mw=%d\mh=%d\n", minmap_w, minmap_h);
	//printf("sq=%d\n", squares);
	////printf("px=%d\n", mspace);
	//while (x <= minmap_w)
	//{
	//	y = 0;
	//	while (y <= minmap_h)
	//	{
	//		mlx_pixel_put(c->rcast->mlx, c->rcast->win, x, y, 0x990000);
	//		y++;
	//	}
	//	x++;
	//}
	//printf("es=%d\n", eachsize / 2);
	int x = 0;
	int y = 0;
	int a = 0;
	int i = 0;
	while (c->map[a])
	{
		x = 0;
		i = 0;
		while (c->map[a][i])
		{
			if(c->map[a][i] == 'N')
			{
				square(c->rcast, x, y, 0xffffff);
				spawn_player(c, x, y);
			}
			else if(c->map[a][i] == '0')
				square(c->rcast, x, y, 0xffffff);
			else if(c->map[a][i] == '1')
				square(c->rcast, x, y, 0x484a57);
			i++;
			x += c->rcast->sq_size + 2;
		}
		y += c->rcast->sq_size + 2;
		a++;
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

int	playermove(t_cub *c)
{
	square(c->rcast, c->rcast->psquarex, c->rcast->psquarey, 0x01ff01);
    draw_player(c);
}

int update(t_cub *c)
{
	int x = 0;
	int y = 0;
    if (c->key_w)
	{
		if(c->rcast->fy >= -1)
		{
			//c->rcast->py--;
			c->rcast->fy -= 0.05;
			c->rcast->py += + c->rcast->fy;
			//printf("fy=%f\n", c->rcast->fy);
		}
		//c->rcast->psquarey--;
	}
    if (c->key_s)
	{
		if(c->rcast->fy < 1)
		{
			//printf("s\n");
			//c->rcast->py++;
			c->rcast->fy += 0.05;
			c->rcast->py += + c->rcast->fy;
			//printf("fy=%f\n", c->rcast->fy);
		}
		//c->rcast->psquarey++;
	}
    if (c->key_a)
	{
		//c->rcast->px--;
		//c->rcast->psquarex--;
	}
    if (c->key_d)
	{
		//c->rcast->px++;
		//c->rcast->psquarex++;
	}
	printf("fy=%f\n", c->rcast->fy);
	playermove(c);
    //clear_image(c);          // wipe old frame
    //mlx_put_image_to_window(c->mlx, c->win, c->img, 0, 0); // display whole frame
    return (0);
}

int key_press(int key, t_cub *c)
{
    if (key == XK_Escape) // ESC
        return close_window(c);
    if (key == XK_w) c->key_w = 1;
    if (key == XK_s) c->key_s = 1;
    if (key == XK_a) c->key_a = 1;
    if (key == XK_d) c->key_d = 1;
    return (0);
}

int key_release(int key, t_cub *c)
{
    if (key == XK_w) c->key_w = 0;
	if (key == XK_s) c->key_s = 0;
    if (key == XK_a) c->key_a = 0;
    if (key == XK_d) c->key_d = 0;
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
