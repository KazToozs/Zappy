/*
** a_incantation.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/server/src/actions/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Jun 22 11:25:18 2016 toozs-_c
** Last update Wed Jun 22 11:25:19 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"

t_lvl_up	g_lvl_up[] =
  {
    {1, &lvl_one},
    {2, &lvl_two},
    {3, &lvl_three},
    {4, &lvl_four},
    {5, &lvl_five},
    {6, &lvl_six},
    {7, &lvl_seven},
    {0, NULL}
  };

int		lvl_one(t_player *player, t_map *map)
{
  if (map->mp[player->pos.x][player->pos.y].ressources[LINEMATE] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[DERAUMERE] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[THYSTAME] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[SIBUR] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[PHIRAS] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[MENDIANE] == 0
      && player_case(map->mp[player->pos.x][player->pos.y], 1, player->level))
    return (1);
  return (0);
}

int		lvl_two(t_player *player, t_map *map)
{
  if (map->mp[player->pos.x][player->pos.y].ressources[LINEMATE] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[DERAUMERE] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[SIBUR] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[MENDIANE] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[PHIRAS] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[THYSTAME] == 0
      && player_case(map->mp[player->pos.x][player->pos.y], 2, player->level))
    return (1);
  return (0);
}

int		player_case(t_case ca, int req_play, int req_level)
{
  int		count;
  t_playercase	*tmp;

  tmp = ca.players;
  count = 0;
  while (tmp != NULL)
    {
      count++;
      tmp = tmp->next;
    }
  if (count != req_play)
    return (0);
  tmp = ca.players;
  while (tmp != NULL)
    {
      if (tmp->player->level != req_level)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

void		increase_levels(t_case ca)
{
  t_playercase	*tmp;

  tmp = ca.players;
  while (tmp != NULL)
    {
      tmp->player->level += 1;
      tmp = tmp->next;
    }
}

int		_incantation(int tabsize, char **tab,
			      t_player *player, t_game *game)
{
  int		i;

  i = -1;
  (void)tabsize;
  (void)tab;
  while (g_lvl_up[++i].lvl != 0 && g_lvl_up[i].lvl != player->level);
  if (g_lvl_up[i].lvl != 0)
    {
      if (g_lvl_up[i].ptr(player, game->map))
	{
	  increase_levels(game->map->mp[player->pos.x][player->pos.y]);
	  if (dprintf(player->client_fd,
		      "niveau actuel %d\n", player->level) < 0)
	    return (1);
	  _pie(game, player->pos.x, player->pos.y, 1);
	  _plv(game, player);
	}
      else
	{
	  if (dprintf(player->client_fd, "ko\n") < 0)
	    return (1);
	  _pie(game, player->pos.x, player->pos.y, 0);
	}
    }
  return (0);
}
