/*
** a_broadcast.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sat Jun 11 12:07:22 2016 toozs-_c
** Last update Mon Jun 20 16:31:04 2016 toozs-_c
*/

#include <stdio.h>
#include <math.h>
#include "actions.h"

int		g_orientation[3][2][2][4] =
  {
    {
      {
	{1, 3, 5, 7},
	{5, 7, 1, 3}
      },
      {
	{1, 3, 5, 7},
	{5, 7, 1, 3}
      }
    },
    {
      {
	{3, 5, 7, 1},
	{3, 5, 7, 1}
      },
      {
	{7, 1, 3, 5},
	{7, 1, 3, 5}
      }
    },
    {
      {
	{2, 4, 6, 8},
	{4, 6, 8, 2}
      },
      {
	{8, 2, 4, 6},
	{6, 8, 2, 4}
      }
    }
  };

int		calc(t_pos pos, int *delta, int axis, t_map *map)
{
  int		val;

  if (axis == 0)
    val = map->size_x;
  else
    val = map->size_y;
  if (abs(pos.x - pos.y) < (val - abs(pos.x - pos.y)))
    {
      *delta = abs(pos.x - pos.y);
      if (pos.x < pos.y)
	return (0);
      else
	return (1);
    }
  else
    {
      *delta = val - abs(pos.x - pos.y);
      if (pos.x < pos.y)
	return (1);
      else
	return (0);
    }
  return (0);
}

int		calculate_direction(t_player *sender, t_player *receiver,
				    t_map *map)
{
  int		deltaX;
  int		deltaY;
  int		yaxis;
  int		xaxis;
  t_pos		pos;

  if (sender->pos.x == receiver->pos.x && sender->pos.y == receiver->pos.y)
    return (0);
  pos.x = sender->pos.x;
  pos.y = receiver->pos.x;
  xaxis = calc(pos, &deltaX, 0, map);
  pos.x = sender->pos.y;
  pos.y = receiver->pos.y;
  yaxis = calc(pos, &deltaY, 1, map);
  if (deltaX == deltaY)
    return (g_orientation[2][xaxis][yaxis][(int)receiver->orientation - 1]);
  else if (deltaX > deltaY)
    return (g_orientation[1][xaxis][yaxis][(int)receiver->orientation - 1]);
  else
    return (g_orientation[0][xaxis][yaxis][(int)receiver->orientation - 1]);
}

int		send_message(t_player *sender, t_player *receiver,
			     t_map *map, char **tab)
{
  int		i;
  int		dir;
  int		tabsize;

  tabsize = -1;
  while (tab[++tabsize]);
  dir = calculate_direction(sender, receiver, map);
  if (dprintf(receiver->client_fd, "message %d,", dir) < 0)
    return (1);
  i = 1;
  while (i < tabsize)
    {
      if (dprintf(receiver->client_fd, " %s", tab[i]) < 0)
	return (1);
      i++;
    }
  if (dprintf(receiver->client_fd, "\n") < 0)
    return (1);
  return (0);
}

int		_broadcast(int tabsize, char **tab,
			   t_player *player, t_game *game)
{
  t_team	*tmp_team;
  t_player	*tmp_pl;

  (void)tabsize;
  tmp_team = game->teams;
  while (tmp_team != NULL)
    {
      tmp_pl = tmp_team->players;
      while (tmp_pl != NULL)
	{
	  if (player->nb != tmp_pl->nb)
	    send_message(player, tmp_pl, game->map, tab);
	  tmp_pl = tmp_pl->next;
	}
      tmp_team = tmp_team->next;
    }
  _pbc(game, player, "BLC");
  if (dprintf(player->client_fd, "ok\n"))
    return (1);
  return (0);
}
