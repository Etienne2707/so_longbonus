
#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "../libft/libft.h"


//struct avec :
	//nombre de move 
	//position du player
	//nombre de collectible
	//nombre de collectible actuel = tant que != 0 ne pas mettre exit
	//position mechant
	//position exit
	//nombre de colonne et ligne
	//double tableau qui contient la map
	//image mur vide perso exit collectible
	//variable mlx et window 
	
typedef struct s_list
{
	int     nb_move;
	int     player_og_col;
	int     player_og_line;
	int     player_col;
	int     player_line;
	int     collect_total;
	int     collect_current;
	int     bad_og_total;
	int     exit_col;
	int     exit_line;
	char    **map;
	void    *img;
	void    *mlx;
	void    *win;
	void 	*img2;
	void	*trainer;
	void	*collectible;
	void	*exit;
	void	*trainer2;
	void	*enemies;
	int 	map_col;
	int	animation;

}	t_list;

void	*mlx_new_window(void *mlx_ptr,int size_x,int size_y,char *title);
int	    handle_keypress(int keysym, t_list *data);
int	    handle_keyrelease(int keysym, void *data);
int 	handle_no_event(void *data);
int 	handle_input(int keysym, t_list *data);
int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
int	close_window(void);
void    ft_croix_axe_x(char **str, int x , int y);
void    ft_croix(char **str, int x, int y);
char	**path_check(int argc, char **argv, char **map);
char	*get_next_line(int fd);
char	*ft_strjoin(char *readed, char *buff);
int		ft_strlen(char *str);
char	*getting_line(char *rest);
int		check(char *str);
char	*trimmed_buff(char *rest);
int		ft_strlen_classic(char *str);
char	**ft_split(char const *s, char c);
int     checker_map(char **tab);
int     check_char(char **tab);
int     check_length(char **tab);
int     check_startend(char **tab);
int     line_count(char **tab);
int     check_full_one(char **tab);
int     one_p_e(char **tab, char c);
char	**gnl_and_check(int argc, char **argv);
void player_pos(t_list *data);
int roadmap(char **str);
int event(int key, t_list *data);
void    refresh(t_list *data);
void	collect_total(t_list *data);
int free_all2(t_list *data);
void     exit_pos(t_list *data);
void    compteur_pas(t_list *data);
char *ft_join(char  *s1, char  *s2);
int	initialisation(int argc, char **argv, t_list *data);
int w_mov(t_list *data, int x, int y);
int s_mov(t_list *data, int x, int y);
int d_mov(t_list *data, int x, int y);
int a_mov(t_list *data, int x, int y);
void	col_max(t_list *data);
int	free_all(char **tab, int i);
int	test(char **str);
void    refresh2(int j, int k, t_list *data);
void check_map_arg(int argc , char *str);
void    check_file(char *map);
void	check_empty_line(char *str);
int	check_c(char **tab);
void	error(char *str, char **tab);





#endif
