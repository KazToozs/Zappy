/*
** actions.h for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/include
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Jun  8 11:11:25 2016 toozs-_c
** Last update Wed Jun 22 11:22:14 2016 toozs-_c
*/

#ifndef ACTIONS_H_
#define ACTIONS_H_

#include "map.h"
#include "game.h"
#include "player.h"
#include "my.h"

typedef struct	s_other
{
  int		i;
  int		x;
  int		y;
}		t_other;

typedef struct	s_set_act
{
  char		*str;
  int		act;
  double	delay;
}		t_set_act;

typedef struct	s_lvl_up
{
  int		lvl;
  int		(*ptr)(t_player *player, t_map *map);
}		t_lvl_up;

typedef struct	s_inv_print
{
  e_resname	res;
  char		*str;
}		t_inv_print;

typedef struct	s_dir_act
{
  e_orien	dir;
  void		(*ptr)(t_player *, t_map *, t_other *);
}		t_dir_act;

typedef struct	s_action_test
{
  //
  char		*action;
  int		(*ptr)(int, char **, t_player *, t_game *);
}		t_action_test;

typedef struct	s_action_exec
{
  e_action	action;
  int		(*ptr)(int, char **, t_player *, t_game *);
}		t_action_exec;

typedef struct	s_action
{
  char		*action;
  e_action	act;
  int		delay;
}		t_action;

extern t_lvl_up g_lvl_up[];

/*
** -------------------
** ----- ACTIONS -----
** -------------------
*/

void		execute_action(char *str,
			       t_player *player, t_game *game);

/*
** --- Avance ---
*/

void		move_up(t_player *player, t_map *map, t_other *o);
void		move_down(t_player *player, t_map *map, t_other *o);
void		move_left(t_player *player, t_map *map, t_other *o);
void		move_right(t_player *player, t_map *map, t_other *o);
int		_avance(int tabsize, char **tab,
			t_player *player, t_game *game);

/*
** --- Droite/Gauche ---
*/

int		_droite(int tabsize, char **tab,
			t_player *player, t_game *game);
int		_gauche(int tabsize, char **tab,
			t_player *player, t_game *game);

/*
** --- Voir ---
*/

void		print_ca_ressources(t_player *player, t_case ca);
void		vue_up(t_player *player, t_map *map, t_other *o);
void		vue_down(t_player *player, t_map *map, t_other *o);
void		vue_left(t_player *player, t_map *map, t_other *o);
void		vue_right(t_player *player, t_map *map, t_other *o);
int		_voir(int tabsize, char **tab, t_player *player, t_game *game);

/*
** --- Inventaire ---
*/

void		print_inventaire(t_player *player, int *inventaire);
int		_inventaire(int tabsize, char **tab,
			    t_player *player, t_game *game);

/*
** --- Prend/Pose ---
*/

e_resname	get_ressource(char *res_name);
int		_prend(int tabsize, char **tab,
		       t_player *player, t_game *game);
int		_pose(int tabsize, char **tab, t_player *player, t_game *game);

/*
** --- Expulse ---
*/

int		_expulse(int tabsize, char **tab,
			 t_player *player, t_game *game);

/*
** --- Broadcast ---
*/

int		_broadcast(int tabsize, char **tab,
			   t_player *player, t_game *game);

/*
** --- Incantation ---
*/

int		lvl_one(t_player *player, t_map *map);
int		lvl_two(t_player *player, t_map *map);
int		lvl_three(t_player *player, t_map *map);
int		lvl_four(t_player *player, t_map *map);
int		lvl_five(t_player *player, t_map *map);
int		lvl_six(t_player *player, t_map *map);
int		lvl_seven(t_player *player, t_map *map);
int		lvl_eight(t_player *player, t_map *map);
int		player_case(t_case ca, int req_play, int req_level);
int		_incantation(int tabsize, char **tab,
			     t_player *player, t_game *game);

/*
** --- Fork ---
*/

int		_fork(int tabsize, char **tab, t_player *player, t_game *game);

/*
** --- Connect nbr ---
*/

int		_connect_nb(int tabsize, char **tab,
			    t_player *player, t_game *game);

/*
** --- Misc ---
*/

t_team		*find_team(t_player *player, t_team *teams);
void		set_timer(int tabsize, char **tab,
			  t_player *player, t_game *game);

#endif
