/*
** a_expulse.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sun Jun 12 19:48:44 2016 toozs-_c
** Last update Mon Jun 20 16:40:27 2016 toozs-_c
*/

#include "actions.h"

int             g_exp_tab[4][4] =
  {
    {5, 7, 1, 3},
    {3, 5, 7, 1},
    {1, 3, 5, 7},
    {7, 1, 3, 5},
  };

t_dir_act	g_dir_exp[] =
  {
    {NORD, &move_up},
    {EST, &move_right},
    {SUD, &move_down},
    {OUEST, &move_left},
    {UNKNOWN, NULL}
  };

int	expulse_player(t_player *player, t_playercase *tmp, t_game *game,
		       int *found)
{
  int		i;
  int		dir;

  if (tmp->player != player)
    {
      i = 0;
      while (g_dir_exp[i].dir != UNKNOWN
	     && g_dir_exp[i].dir != player->orientation)
	i++;
      if (g_dir_exp[i].dir != UNKNOWN)
	g_dir_exp[i].ptr(tmp->player, game->map, NULL);
      dir = g_exp_tab[((int)player->orientation) - 1]
	[((int)tmp->player->orientation) - 1];
      _pex(game, player);
      *found = 1;
      if (dprintf(tmp->player->client_fd, "deplacement: %d\n", dir) < 0)
	return (1);
    }
  return (0);
}

int		expulse_player_loop(t_player *player, t_game *game, char **tab)
{
  t_playercase	*tmp;
  int		found;

  (void)tab;
  tmp = game->map->mp[player->pos.x][player->pos.y].players;
  found = 0;
  while (tmp != NULL)
    {
      expulse_player(player, tmp, game, &found);
      tmp = tmp->next;
    }
  if (found == 0)
    return (1);
  return (0);
}

int		_expulse(int tabsize, char **tab,
			 t_player *player, t_game *game)
{
  t_playercase	*tmp;

  (void)tabsize;
  tmp = game->map->mp[player->pos.x][player->pos.y].players;
  if (tmp == NULL)
    {
      if (dprintf(player->client_fd, "ko\n") < 0)
	return (1);
      else
	return (0);
    }
  if (expulse_player_loop(player, game, tab))
    {
      if (dprintf(player->client_fd, "ko\n") < 0)
	return (1);
      return (0);
    }
  if (dprintf(player->client_fd, "ok\n") < 0)
    return (1);
  return (0);
}
