/*
** move.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Jun  8 19:01:18 2016 toozs-_c
** Last update Wed Jun 22 11:34:52 2016 toozs-_c
*/

#include "actions.h"

void		remove_pl_from_case(t_player *player, t_case *ca)
{
  t_playercase	*tmp;
  int		found;

  tmp = ca->players;
  found = 0;
  while (ca->players != NULL && found == 0)
    {
      if (ca->players->player == player)
        found = 1;
      if (found == 0)
        ca->players = ca->players->next;
    }
  case_remove_node(&tmp, &ca->players);
  ca->players = tmp;
}

void		move_up(t_player *player, t_map *map, t_other *o)
{
  (void)o;
  remove_pl_from_case(player, &map->mp[player->pos.x][player->pos.y]);
  player->pos.y = (player->pos.y - 1) % map->size_y;
  if (player->pos.y < 0)
    player->pos.y = map->size_y - 1;
  case_push_back(&map->mp[player->pos.x][player->pos.y].players, player);
}

void		move_down(t_player *player, t_map *map, t_other *o)
{
  (void)o;
  remove_pl_from_case(player, &map->mp[player->pos.x][player->pos.y]);
  player->pos.y = (player->pos.y + 1) % map->size_y;
  if (player->pos.y < 0)
    player->pos.y = map->size_y - 1;
  case_push_back(&map->mp[player->pos.x][player->pos.y].players, player);
}

void		move_left(t_player *player, t_map *map, t_other *o)
{
  (void)o;
  remove_pl_from_case(player, &map->mp[player->pos.x][player->pos.y]);
  player->pos.x = (player->pos.x - 1) % map->size_x;
  if (player->pos.x < 0)
    player->pos.x = map->size_x - 1;
  case_push_back(&map->mp[player->pos.x][player->pos.y].players, player);
}

void		move_right(t_player *player, t_map *map, t_other *o)
{
  (void)o;
  remove_pl_from_case(player, &map->mp[player->pos.x][player->pos.y]);
  player->pos.x = (player->pos.x + 1) % map->size_x;
  if (player->pos.x < 0)
    player->pos.x = map->size_x - 1;
  case_push_back(&map->mp[player->pos.x][player->pos.y].players, player);
}
