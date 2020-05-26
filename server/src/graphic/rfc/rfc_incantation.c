/*
** rfc_incantation.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
**
** Made by pallua_j
** Login   <pallua_j@epitech.net>
**
** Started on  Mon Jun 13 11:13:00 2016 pallua_j
** Last update Fri Jun 24 10:52:51 2016 toozs-_c
*/

#include <stdio.h>
#include "game.h"

t_fds		*print_return(t_fds *tmpg)
{
  if (dprintf(tmpg->fd, "\n") < 0)
    tmpg = tmpg->next;
  else
    tmpg = tmpg->next;
  return (tmpg);
}

void	       	_pic(t_game *this, t_player *pl)
{
  t_fds		*tmpg;
  t_playercase	*tmp;
  int		nb;

  tmpg = this->fd_graph;
  while (tmpg)
    {
      tmp = this->map->mp[pl->pos.x][pl->pos.y].players;
      if (dprintf(tmpg->fd, "pic %d %d %d %d",
		  pl->pos.x, pl->pos.y, pl->level, pl->nb) < 0)
	tmpg = tmpg->next;
      else
	{
	  nb = pl->nb;
	  while (tmp)
	    {
	      if (nb != tmp->player->nb)
		if (dprintf(tmpg->fd, " %d", tmp->player->nb) < 0)
		  break ;
	      tmp = tmp->next;
	    }
	  tmpg = print_return(tmpg);
	}
    }
}

void		_pie(t_game *this, int x, int y, int R)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      if (dprintf(tmp->fd, "pie %d %d %d\n", x, y, R) < 0)
	tmp = tmp->next;
      else
	tmp = tmp->next;
    }
}
