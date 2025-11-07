/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:39:33 by zzin              #+#    #+#             */
/*   Updated: 2025/11/07 21:27:36 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"

void	*init_mlx(void)
{
	t_mlx	*m;
	void	*mlxp;

	//mlxp = mlx_init();
	//if(!mlxp)
	//	return (NULL);
	//m = save(sizeof(t_mlx));
	//m->mlx = mlxp;
	//new_node(&cubs->heap, m->mlx);
	//mlx_get_screen_size(m->mlx, &m->x, &m->y);
	//m->win = mlx_new_window();
	return m;
}

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
			if(map[a][c] == 'P')
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

void	init_cub(void)
{
	t_mlx	*m;

	if(!cubs || cubs->rcast)
		return ;
	cubs->rcast = save(sizeof(t_rcast));
	char	*map[] = {"1111111",
					  "1000001",
				 	  "10000P1",
				 	  "1000001",
					  "1111111",
				  NULL,
				};
	
	cubs->map = map;
	prmap(map);
	//m = init_mlx();
	//if(!m)
	//	return ;
	//cubs->rcast->mlx = m;
	return ;
}
