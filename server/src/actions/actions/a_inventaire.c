/*
** a_inventaire.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Jun  9 19:48:58 2016 toozs-_c
** Last update Thu Jun 16 11:47:22 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"

int		_inventaire(int tabsize, char **tab,
			    t_player *player, t_game *game)
{
  (void)tabsize;
  (void)tab;
  (void)game;
  if (dprintf(player->client_fd, "{") < 0)
    return (1);
  print_inventaire(player, player->inventaire);
  if (dprintf(player->client_fd, "}\n") < 0)
    return (1);
  return (0);
}
