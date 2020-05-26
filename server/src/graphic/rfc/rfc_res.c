/*
** rfc_res.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Jun 13 12:12:16 2016 pallua_j
** Last update Fri Jun 24 10:53:12 2016 toozs-_c
*/

#include <stdio.h>
#include "game.h"

void		_pdr(t_game *this, t_player *pl, e_resname name)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "pdr %d %d\n", pl->nb, name) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_pgt(t_game *this, t_player *pl, e_resname name)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "pgt %d %d\n", pl->nb, name) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_pdi(t_game *this, t_player *pl)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "pdi %d\n", pl->nb) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}
