/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:59 by araji             #+#    #+#             */
/*   Updated: 2025/10/18 17:26:47 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBPARSER_H
#define CUBPARSER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef enum e_texture
{
	NO,
	SO,
	WE,
	EA
}	t_texture;

typedef enum e_color
{
	FULL,
	RED,
	GREEN,
	BLUE
}	t_color;

typedef struct s_cub
{
	char	*textures[4];	// NO, SO, WE, EA
	int		flr_rgb[4];		// [0] is the whole color, [1] R, [2] G, [3] B
	int		ceiling_rgb[4];	// [0] is the whole color, [1] R, [2] G, [3] B
	char	**map;
	int		mwidth;
	int		mheight;
}	t_cub;



int		check_extension(char *filename);
int 	init_struct(t_cub **data);
int		parse_file(char *filename, t_cub **data);


int		get_textures(char *line, t_cub **data);
int		get_colors(char *line, t_cub **data);
int		get_map(char *line, t_cub **data);
int 	extract_data(char *line, t_cub **data);


int		skip_leading_whitespace(char *line);
int		data_collected(t_cub **data);
size_t	ft_strlen(char *filename);
int		ft_strcmp(char *s1, char *s2);
int		empty_line(char *line);
char	**ft_split(char const *s, char c, int *count);


/* getnextline */

typedef struct node
{
	char		*str;
	int			len;
	struct node	*next;
}	t_list;

int		get_line_len(t_list *tmp);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *content);
char	*get_next_line(int fd);
void	lst_add_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

#endif