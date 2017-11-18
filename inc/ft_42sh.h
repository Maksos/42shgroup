/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:20:47 by maastie           #+#    #+#             */
/*   Updated: 2017/09/09 15:20:47 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_H
# define FT_42SH_H

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/param.h>
# include <stdlib.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/resource.h>
# include <time.h>
# include <signal.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include "../libft/includes/libft.h"

typedef struct stat		t_stat;
struct winsize			wws;
struct s_data			*d;
struct s_term			*t;

typedef struct			s_term
{
	char				*line;
	char				**history;
	char				*xcpy;
	int					hi;
	int					x;
	int					y;
	int					ys;

}						t_term;

typedef struct			s_red
{
	char				*act;
	char				**cmd;
	struct	s_red		*nxt;
}						t_red;

typedef struct 			s_pp//  2>&1 ls -l  cat -e > ok 1>&- && pwd || ok ; lasdasd 'asdawdada' a{awdawd}a $
{
	char				*cmd; 
	char				*act;
	struct s_pp			*pipe;
	struct s_pp			*nxt;
	struct s_red		*red;
}						t_pp;

typedef struct			s_data
{
	int 				pdes[2];
	struct s_pp			*bpp;
	struct s_pp			*fpp;
	char				**env;
	char				**tenv;
	char				*read;
	int					andor;
	int					ph;
}						t_data;

int		exec_by_p(char **env, char **cmd, char **by, int i);
char			*fill_r(char *s, char *r, char *d);

int						clear_opt(char **s);// tools
char					**del_and_ajust_tab(char **s, int i);
char					*ft_concat(char *p, char *pre);//tools
char					*fill_r(char *s, char *r, char *d); // tools ?
char					*ft_search_and_r(char *ref, char *fill);//tools
char					*fill_c(char *s, char *d, char *p);//tools
char					*ft_search_and_c(char *r, char *c, char *p); // tools
int						exec_solo(t_pp *c); // no need
int						check_built_in(char **cmd); // tools
int						ft_cd(char **cmd);
int						ft_env(char **cmd);
int						ft_export(char **cmd);
int						ft_unsetenv(char **cmd);
int						ft_setenv(char **cmd);
int						built_in(char **cmd);
int						ft_tab(void);
int						do_red_fd(t_red *r, char *act);
int						l_red(char **cmd, int i);
int						ll_red(t_red *r);
int						rr_red(char **cmd);
int						r_red(char **cmd);
int						check_red_data(t_red *r);
int						check_pipe_data(t_pp *p);
int						exec_it(t_red *r, char **env);
int						exec_red(t_pp *r);
int						exec_red_f(t_pp *r);
//
int						ftt_pipe(t_pp *p);
int						ft_pipe(t_pp *p);
//
int						red_fd(t_red *r);
int						exec_pp(t_pp *c);
int						ft_b_f_red(char *s, t_red *r, int i);
int						pp(char *s);
int						ft_new_pp(char *s, int i);
int						pp_in(void);
int						pp_red(void);
int						ft_clear_term(void);
int						ft_putterm(int c);
void					ft_free_pp(t_pp *b);
void					ft_free_all(void);
void					arrows_more(char *buff);
void					alt_xcv(char *buff);
void					ft_refresh(void);
void					ft_khome(void);
void					ft_kright(void);
void					ft_kend(void);
void					ft_delete(void);
void					ft_kleft(void);
void					ctrl_shift(char *buff);
void					ft_signal(void);
void					default_term(void);
char					*ncpy(char *l, int s);
char					*del_index(char *line, int x);
char					*ft_adchar(char *s, char c);
char					*add_char(char *s, char *n);
char					**add_new(char **tabl, char *s, int i, int k);
char					**ft_free_tab(char **tabl);
char					**cpy_tab(char **dst, char **src, int k);
int						ft_kenter(void);
int						quoted(void);
int						init_termcap(int fd);
int						ft_putterm(int c);
int						termread(void);
int						begin_termcaps_read(void);
int						ft_error(int error, int ret);

#endif
