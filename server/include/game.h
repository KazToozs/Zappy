/*
** game.h for zappy in /home/pallua_j/rendu/tmp/zappy/include
**
** Made by pallua_j
** Login   <pallua_j@epitech.net>
**
** Started on  Tue Jun  7 17:03:06 2016 pallua_j
** Last update Fri Jun 24 13:42:42 2016 toozs-_c
*/

#ifndef _GAME__H_
# define _GAME__H_

#include <stdbool.h>
#include <time.h>
#include "map.h"
#include "parameters.h"
#include "team.h"
#include "fds.h"

typedef struct		s_game
{
  t_team		*teams;
  int			game_delay;
  int			ccount;
  t_fds			*fd_graph;
  t_map			*map;
}			t_game;

typedef struct		s_graphact
{
  char			*act;
  bool			(*ptr)(t_game *, char **, int);
}			t_graphact;

void			my_clock_gettime(struct timespec *);

t_game			*create_game(t_data *);
char			**my_str_tab(char *);

void			do_graph_action(t_game *, char *, int);
void			start_graph(t_game *, int);

int			do_action(t_game *);
int			get_ccount(t_game *, char *);
int			player_push_back(t_player **, int, t_game *, char *);
int			player_push_back_ghost(t_player **, int, t_game *, char *);

void			add_food(t_game *);

/*
** Gameloop
*/

void		check_food(t_game *game);
void		check_eggs(t_game *game);

/*
** Fonction RFC 4894
*/

void		size_map_graph(t_game *, int);
void		print_case_graph(t_game *, int, int, int);
void		print_map_graph(t_game *, int);
void		print_team_graph(t_game *, int);
void		print_time_graph(t_game *, int);
void		change_time_graph(t_game *, int, int);
void		player_position_graph(t_player *, int);
void		player_level_graph(t_player *, int);
void		player_inventaire_graph(t_player *, int);

void		_sgt(t_game *);
void		_ppo(t_game *, t_player *);
void		_plv(t_game *, t_player *);
void		_pin(t_game *, t_player *);
void		_msz(t_game *);
void		_bct(t_game *, int, int);
void		_tna(t_game *);
void		_mct(t_game *);
void		_pnw(t_game *, t_player *);
void		_pex(t_game *, t_player *);
void		_pbc(t_game *, t_player *, char*);
void		_smg(t_game *, char *);
void		_seg(t_game *, char *);
void		_pic(t_game *, t_player *);
void		_pie(t_game *, int, int, int);
void		_pfk(t_game *, t_player *);
void		_enw(t_game *, t_egg *, t_player *);
void		_eht(t_game *, t_egg *);
void		_ebo(t_game *, t_egg *);
void		_edi(t_game *, t_egg *);
void		_pdr(t_game *, t_player *, e_resname);
void		_pgt(t_game *, t_player *, e_resname);
void		_pdi(t_game *, t_player *);

/*
** Fonction pointeur sur fonction
*/

bool		_msz_ptr(t_game *, char **, int);
bool		_bct_ptr(t_game *, char **, int);
bool		_mct_ptr(t_game *, char **, int);
bool		_tna_ptr(t_game *, char **, int);
bool		_ppo_ptr(t_game *, char **, int);
bool		_plv_ptr(t_game *, char **, int);
bool		_pin_ptr(t_game *, char **, int);
bool		_sgt_ptr(t_game *, char **, int);
bool		_sst_ptr(t_game *, char **, int);

#endif /*_GAME__H_*/
