/*
** rfc_player.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Jun  8 13:00:32 2016 pallua_j
** Last update Wed Jun 22 10:44:04 2016 toozs-_c
*/

#include "game.h"

void		_pnw(t_game *this, t_player *pl)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "pnw %d %d %d %d %d %s\n",
		  pl->nb, pl->pos.x, pl->pos.y, pl->orientation,
		  pl->level, pl->team_name) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_pex(t_game *this, t_player*pl)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "pex %d\n", pl->nb) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}

void		_ppo(t_game *this, t_player *pl)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      player_position_graph(pl, tmp->fd);
      tmp = tmp->next;
    }
}

void		_plv(t_game *this, t_player *pl)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      player_level_graph(pl, tmp->fd);
      tmp = tmp->next;
    }
}

void		_pin(t_game *this, t_player *pl)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      player_inventaire_graph(pl, tmp->fd);
      tmp = tmp->next;
    }
}
