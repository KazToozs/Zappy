/*
** timers.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Jun 13 13:42:11 2016 toozs-_c
** Last update Fri Jun 24 13:47:53 2016 toozs-_c
*/

#include "actions.h"
#include "server.h"

t_action		g_acts[] =
  {
    {"avance", AVANCE, 7},
    {"droite", DROITE, 7},
    {"gauche", GAUCHE, 7},
    {"voir", VOIR, 7},
    {"inventaire", INVENTAIRE, 1},
    {"prend", PREND, 7},
    {"pose", POSE, 7},
    {"expulse", EXPULSE, 7},
    {"broadcast", BROADCAST, 7},
    {"incantation", INCANTATION, 300},
    {"fork", FORK, 42},
    {"connect_nbr", CONNECT, 0},
    {NULL, NOTHING, 0}
  };

void		my_clock_gettime(struct timespec *time)
{
  int		ret;

  ret = clock_gettime(CLOCK_MONOTONIC, time);
  if (ret == 0)
    return ;
  else
    {
      free_ptrs(&g_ptrs);
      exit(1);
    }
}

int		incantation_case(t_game *game, t_player *player)
{
  int		i;

  i = 0;
  while (g_lvl_up[i].lvl != 0 && g_lvl_up[i].lvl != player->level)
    i++;
  if (g_lvl_up[i].lvl != 0 && g_lvl_up[i].ptr(player, game->map))
    {
      if (dprintf(player->client_fd, "elevation en cours\n") < 0)
	return (1);
      _pic(game, player);
      return (0);
    }
  else
    {
      if (dprintf(player->client_fd, "ko\n") < 0)
	return (1);
      cmd_remove_node(&player->queue, &player->queue);
    }
  return (1);
}

int		set_action(int tabsize, t_player *player, t_game *game, int i)
{
  if (!my_strcmp(g_acts[i].action, "prend")
      || !my_strcmp(g_acts[i].action, "pose")
      || !my_strcmp(g_acts[i].action, "broadcast"))
    {
      if (tabsize < 2)
	{
	  if (dprintf(player->client_fd, "ko\n") < 0)
	    return (1);
	  return (1);
	}
    }
  if (g_acts[i].act == INCANTATION)
    if (incantation_case(game, player))
      return (1);
  if (g_acts[i].act == FORK)
    _pfk(game, player);
  player->action = g_acts[i].act;
  clock_gettime(CLOCK_MONOTONIC, &player->timer);
  player->delay = ((double)g_acts[i].delay);
  return (0);
}

void		set_timer(int tabsize, char **tab,
			  t_player *player, t_game *game)
{
  int		i;

  i = 0;
  while (my_strcmp(g_acts[i].action, tab[0]) && g_acts[i].action != NULL)
    i++;
  if (g_acts[i].action != NULL)
    {
      set_action(tabsize, player, game, i);
    }
  else
    {
      cmd_remove_node(&player->queue, &player->queue);
      if (dprintf(player->client_fd, "ko\n") < 0)
	return ;
    }
}
