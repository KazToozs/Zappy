/*
** a_gauche.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Jun  9 10:57:00 2016 toozs-_c
** Last update Sat Jun 18 18:19:15 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"

int		_gauche(int tabsize, char **tab,
			t_player *player, t_game *game)
{
  int		tmp;

  (void)tabsize;
  (void)tab;
  (void)game;
  tmp = ((int)player->orientation - 1);
  if (tmp <= 0)
    tmp = 4;
  player->orientation = (e_orien)tmp;
  if (dprintf(player->client_fd, "ok\n") < 0)
    return (1);
  _ppo(game, player);
  return (0);
}
