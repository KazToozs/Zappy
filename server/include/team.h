/*
** team.h for zappy in /home/toozs-_c/tek2/zappy_args/include
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun  7 13:20:28 2016 toozs-_c
** Last update Wed Jun  8 10:25:19 2016 toozs-_c
*/

#ifndef TEAM_H_
#define TEAM_H_

#include "player.h"
#include "egg.h"

typedef struct	s_team
{
  t_player	*players;
  char		*name;
  int		current_nb;
  int		max_nb;
  t_egg		*eggs;
  struct s_team *next;
  struct s_team	*prev;
}		t_team;

int		team_push_back(t_team **list, char *name);
void		team_remove_node(t_team **head, t_team **node);

#endif
