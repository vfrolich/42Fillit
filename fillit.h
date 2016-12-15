/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:37:13 by arosset           #+#    #+#             */
/*   Updated: 2016/12/15 19:06:58 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./../libft/libft.h"

typedef struct		s_lst
{
	char			**tetri;
	char			letter;
	int				use;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

int					ft_usage(int c);
char				*ft_acquisition(char *argv);
int					ft_check_error(char *str);
int					ft_check_char(char *str);
int					ft_check_format(char *str);
int					ft_check_tetri(char *str);
char				*ft_open_extern(void);
int					ft_count_tetri(char **raw_tetri);
void				ft_lst_fill(char **raw_tetri, t_lst *lst, char c);
t_lst				*ft_lstcreate_one();
t_lst				*ft_lstcreate(char **raw_tetri);
t_lst				*ft_mainlst(char *str);
t_lst				*ft_reset_lst(t_lst *lst);
t_lst				*ft_lststart(t_lst *lst);
int					ft_lst_used(t_lst *lst);
char				**ft_move_top(char **tetri);
char				**ft_move_left(char **tetri);
int					ft_tetri_comp(char **tetri, t_lst *ref);
int					ft_main_check(t_lst *lst);
int					ft_check_empty(char **tetri);
int					*ft_transform(t_lst *lst);
int					ft_good_place(char **tetri);
int					ft_check_pos(char **grid, char **tetri, int y, int x);
void				ft_main_resolution(t_lst *lst, int i);
int					ft_check_resolution(char **grid, t_lst *lst, int y, int x);
char				**ft_resolution(char **grid, t_lst *lst, int y, int x);
char				**ft_create_tab(int i);
char				**ft_tetri_to_tab(char **grid, char **tetri, int y, int x);
char				**ft_del_tetri(char **grid, t_lst *lst);
void				ft_print_tab(char **tab);
#endif
