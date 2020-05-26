/*
** rfc_player.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Jun  8 13:00:32 2016 pallua_j
** Last update Mon Jun 20 10:37:33 2016 toozs-_c
*/

#include "game.h"

void		player_position_graph(t_player *pl, int fd)
{
  if (dprintf(fd, "ppo %d %d %d %d\n",
	      pl->nb, pl->pos.x, pl->pos.y, pl->orientation) < 0)
    return ;
}

void		player_level_graph(t_player *pl, int fd)
{
  if (dprintf(fd, "plv %d %d\n", pl->nb, pl->level) < 0)
    return ;
}

void		player_inventaire_graph(t_player *pl, int fd)
{
  if (dprintf(fd, "pin %d %d %d %d %d %d %d %d %d %d\n",
	      pl->nb, pl->pos.x, pl->pos.y, pl->inventaire[NOURRITURE],
	      pl->inventaire[LINEMATE], pl->inventaire[DERAUMERE],
	      pl->inventaire[SIBUR], pl->inventaire[MENDIANE],
	      pl->inventaire[PHIRAS], pl->inventaire[THYSTAME]) < 0)
    return ;
}
