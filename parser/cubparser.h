/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:59 by araji             #+#    #+#             */
/*   Updated: 2025/10/15 21:22:30 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBPARSER_H
#define CUBPARSER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

enum e_texture
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_cub
{
	char	*textures[4];	// NO, SO, WE, EA
	int		flr_rgb[4];		// [0] is the whole color, [1] R, [2] G, [3] B
	int		ceiling_rgb[4];	// [0] is the whole color, [1] R, [2] G, [3] B
	char	**map;
	int		mwidth;
	int		mheight;
}	t_cub;












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
void	extract(t_list *lst, char **line);
char	*get_next_line(int fd);
int		found_newline(t_list *node);
void	lst_add_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	create_t_list(t_list **lst, int fd);
void	clean(t_list **lst);

#endif