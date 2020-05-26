/*
** a_avance.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Jun  8 12:33:28 2016 toozs-_c
** Last update Wed Jun 22 11:24:55 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"

t_dir_act	g_dir_mov[] =
  {
    {NORD, &move_up},
    {EST, &move_right},
    {SUD, &move_down},
    {OUEST, &move_left},
    {UNKNOWN, NULL}
  };

int		_avance(int tabsize, char **tab,
			t_player *player, t_game *game)
{
  int		i;

  i = 0;
  (void)tabsize;
  (void)tab;
  while (g_dir_mov[i].dir != player->orientation
	 && g_dir_mov[i].dir != UNKNOWN)
    i++;
  if (g_dir_mov[i].dir != UNKNOWN)
    g_dir_mov[i].ptr(player, game->map, NULL);
  if (dprintf(player->client_fd, "ok\n") < 0)
    return (1);
  _ppo(game, player);
  return (0);
}
