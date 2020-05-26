/*
** a_connect.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Jun  9 20:39:37 2016 toozs-_c
** Last update Thu Jun 16 11:20:04 2016 toozs-_c
*/

#include "actions.h"

int		_connect_nb(int tabsize, char **tab,
			    t_player *player, t_game *game)
{
  t_team	*tmp;
  int		val;

  (void)tabsize;
  (void)tab;
  val = -1;
  if ((tmp = find_team(player, game->teams)))
    val = tmp->max_nb - tmp->current_nb;
  if (dprintf(player->client_fd, "%d\n", val) < 0)
    return (1);
  return (0);
}
