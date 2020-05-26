/*
** a_droite.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Jun  9 11:20:14 2016 toozs-_c
** Last update Sat Jun 18 18:19:01 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"

int		_droite(int tabsize, char **tab, t_player *player, t_game *game)
{
  int		tmp;

  (void)tabsize;
  (void)tab;
  (void)game;
  tmp = ((int)player->orientation + 1);
  if (tmp >= 5)
    tmp = 1;
  player->orientation = (e_orien)tmp;
  if (dprintf(player->client_fd, "ok\n") < 0)
    return (1);
  _ppo(game, player);
  return (0);
}
