/*
** levelup.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sat Jun 11 19:20:43 2016 toozs-_c
** Last update Tue Jun 21 10:59:10 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"

int		lvl_three(t_player *player, t_map *map)
{
  if (map->mp[player->pos.x][player->pos.y].ressources[LINEMATE] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[PHIRAS] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[SIBUR] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[MENDIANE] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[THYSTAME] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[DERAUMERE] == 0
      && player_case(map->mp[player->pos.x][player->pos.y], 2, player->level))
    return (1);
  return (0);
}

int		lvl_four(t_player *player, t_map *map)
{
  if (map->mp[player->pos.x][player->pos.y].ressources[LINEMATE] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[PHIRAS] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[DERAUMERE] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[SIBUR] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[THYSTAME] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[MENDIANE] == 0
      && player_case(map->mp[player->pos.x][player->pos.y], 4, player->level))
    return (1);
  return (0);
}

int		lvl_five(t_player *player, t_map *map)
{
  if (map->mp[player->pos.x][player->pos.y].ressources[LINEMATE] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[MENDIANE] == 3
      && map->mp[player->pos.x][player->pos.y].ressources[DERAUMERE] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[SIBUR] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[PHIRAS] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[THYSTAME] == 0
      && player_case(map->mp[player->pos.x][player->pos.y], 4, player->level))
    return (1);
  return (0);
}

int		lvl_six(t_player *player, t_map *map)
{
  if (map->mp[player->pos.x][player->pos.y].ressources[LINEMATE] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[PHIRAS] == 1
      && map->mp[player->pos.x][player->pos.y].ressources[DERAUMERE] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[SIBUR] == 3
      && map->mp[player->pos.x][player->pos.y].ressources[THYSTAME] == 0
      && map->mp[player->pos.x][player->pos.y].ressources[MENDIANE] == 0
      && player_case(map->mp[player->pos.x][player->pos.y], 6, player->level))
    return (1);
  return (0);
}

int		lvl_seven(t_player *player, t_map *map)
{
  if (map->mp[player->pos.x][player->pos.y].ressources[LINEMATE] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[PHIRAS] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[DERAUMERE] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[SIBUR] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[THYSTAME] == 2
      && map->mp[player->pos.x][player->pos.y].ressources[MENDIANE] == 0
      && player_case(map->mp[player->pos.x][player->pos.y], 6, player->level))
    return (1);
  return (0);
}
