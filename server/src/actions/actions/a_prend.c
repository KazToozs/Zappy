/*
** a_prend.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Jun  9 12:19:23 2016 toozs-_c
** Last update Sat Jun 18 18:34:53 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"

int		_prend(int tabsize, char **tab, t_player *player, t_game *game)
{
  e_resname	ress;

  (void)tabsize;
  if ((ress = get_ressource(tab[1])) == NONE)
    {
      if (dprintf(player->client_fd, "ko\n") < 0)
	return (1);
      return (1);
    }
  if (game->map->mp[player->pos.x][player->pos.y].ressources[ress] > 0)
    {
      game->map->mp[player->pos.x][player->pos.y].ressources[ress] -= 1;
      player->inventaire[ress] += 1;
      if (ress == NOURRITURE)
	player->life += 126;
      if (dprintf(player->client_fd, "ok\n") < 0)
	return (1);
      _pgt(game, player, ress);
      _pin(game, player);
      _bct(game, player->pos.x, player->pos.y);
    }
  else
    if (dprintf(player->client_fd, "ko\n") < 0)
      return (1);
  return (0);
}
