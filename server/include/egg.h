/*
** egg.h for zappy in /home/pallua_j/rendu/tmp/zappy/include
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Jun  7 17:17:52 2016 pallua_j
** Last update Fri Jun 24 13:48:50 2016 toozs-_c
*/

#ifndef _EGG__H_
# define _EGG__H_

#include "player.h"

typedef struct		s_egg
{
  struct s_egg		*prev;
  double		time;
  struct timespec	start;
  char			*team_name;
  int			nb;
  int			nb_aut;
  t_pos			pos;
  struct s_egg		*next;
}			t_egg;

int			egg_push_back(t_egg **, t_pos, char *);
void			egg_remove_node(t_egg **, t_egg **);

#endif /*!_EGG__H_*/
