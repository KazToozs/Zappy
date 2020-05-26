/*
** rfc_egg.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Jun 13 11:43:38 2016 pallua_j
** Last update Fri Jun 24 10:51:49 2016 toozs-_c
*/

#include <stdio.h>
#include "game.h"

void		_pfk(t_game *this, t_player *pl)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "pfk %d\n", pl->nb) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_enw(t_game *this, t_egg *egg, t_player *pl)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "enw %d %d %d %d\n",
		  egg->nb, pl->nb, egg->pos.x, egg->pos.y) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_eht(t_game *this, t_egg *egg)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "eht %d\n", egg->nb) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_ebo(t_game *this, t_egg *egg)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "ebo %d\n", egg->nb) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_edi(t_game *this, t_egg *egg)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "edi %d\n", egg->nb) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}
