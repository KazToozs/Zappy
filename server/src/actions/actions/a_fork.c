/*
** a_fork.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sat Jun 11 10:15:51 2016 toozs-_c
** Last update Sat Jun 18 18:13:56 2016 toozs-_c
*/

#include "actions.h"

int		_fork(int tabsize, char **tab,
		      t_player *player, t_game *game)
{
  t_team	*tmp;
  t_egg		*etmp;

  (void)tabsize;
  (void)tab;
  if ((tmp = find_team(player, game->teams)))
    egg_push_back(&tmp->eggs, player->pos, player->team_name);
  if (dprintf(player->client_fd, "ok\n") < 0)
    return (1);
  etmp = tmp->eggs;
  while (etmp != NULL && etmp->next != NULL)
    {
      etmp = etmp->next;
    }
  if (etmp)
    _enw(game, etmp, player);
  return (0);
}
