/*
** player.h for zappy in /home/pallua_j/rendu/tmp/zappy/include
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Jun  7 17:15:27 2016 pallua_j
** Last update Fri Jun 24 13:41:59 2016 toozs-_c
*/

#ifndef _PLAYER__H_
# define _PLAYER__H_

#include "cmd_queue.h"

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef enum		e_orien
  {
    UNKNOWN = 0,
    NORD = 1,
    EST = 2,
    SUD = 3,
    OUEST = 4
  }			e_orien;

typedef enum		e_action
  {
    NOTHING,
    AVANCE,
    DROITE,
    GAUCHE,
    VOIR,
    INVENTAIRE,
    PREND,
    POSE,
    EXPULSE,
    BROADCAST,
    INCANTATION,
    FORK,
    CONNECT
  }			e_action;

typedef struct		s_player
{
  struct s_player	*prev;
  double		life;
  int			client_fd;
  int			nb;
  char			*team_name;
  int			inventaire[7];
  t_cmd			*queue;
  t_pos			pos;
  e_orien		orientation;
  e_action		action;
  double		delay;
  struct timespec	timer;
  struct timespec	start;
  int			ghost;
  int			level;
  struct s_player	*next;
}			t_player;

void			player_remove_node(t_player **, t_player **);

#endif /*!_PLAYER__H_*/
