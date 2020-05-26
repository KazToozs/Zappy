/*
** rfc_message.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Jun 13 10:41:41 2016 pallua_j
** Last update Fri Jun 24 10:53:03 2016 toozs-_c
*/

#include <stdio.h>
#include "game.h"

void		_pbc(t_game *this, t_player *pl, char *message)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "pbc %d %s\n", pl->nb, message) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_smg(t_game *this, char *message)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "smg %s\n", message) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_seg(t_game *this, char *teamname)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "seg %s\n", teamname) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}
