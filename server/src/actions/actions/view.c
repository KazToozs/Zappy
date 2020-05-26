/*
** view.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Jun  9 16:45:47 2016 toozs-_c
** Last update Thu Jun 23 17:08:59 2016 toozs-_c
*/

#include "actions.h"

void		calculate_coordinates(t_player *player, t_map *map, t_other *o)
{
  int		tmp_x;
  int		tmp_y;

  tmp_x = player->pos.x + o->x;
  tmp_y = player->pos.y + o->y;
  while (tmp_x < 0)
    {
      tmp_x = tmp_x + map->size_x;
    }
  while (tmp_y < 0)
    {
      tmp_y = tmp_y + map->size_y;
    }
  while (tmp_x >= map->size_x)
    {
      tmp_x = tmp_x - map->size_x;
    }
  while (tmp_y >= map->size_y)
    {
      tmp_y = tmp_y - map->size_y;
    }
  o->x = tmp_x;
  o->y = tmp_y;
}

void		vue_up(t_player *player, t_map *map, t_other *o)
{
  int		col_offset;
  int		row_offset;
  int		row_i;
  int		i;

  col_offset = -1;
  row_offset = -(player->level);
  row_i = row_offset;
  i = 1;
  while (i != o->i)
    {
      i++;
      if (row_i < -(row_offset))
	row_i++;
      else
	{
	  row_offset -= 1;
	  row_i = row_offset;
	  col_offset -= 1;
	}
    }
  o->y = col_offset;
  o->x = row_i;
  calculate_coordinates(player, map, o);
}

void		vue_right(t_player *player, t_map *map, t_other *o)
{
  int		col_offset;
  int		row_offset;
  int		row_i;
  int		i;

  col_offset = 1;
  row_offset = -(player->level);
  row_i = row_offset;
  i = 1;
  while (i != o->i)
    {
      i++;
      if (row_i < -(row_offset))
	row_i++;
      else
	{
	  row_offset -= 1;
	  row_i = row_offset;
	  col_offset += 1;
	}
    }
  o->y = row_i;
  o->x = col_offset;
  calculate_coordinates(player, map, o);
}

void		vue_down(t_player *player, t_map *map, t_other *o)
{
  int		col_offset;
  int		row_offset;
  int		row_i;
  int		i;

  col_offset = 1;
  row_offset = (player->level);
  row_i = row_offset;
  i = 1;
  while (i != o->i)
    {
      i++;
      if (row_i > -(row_offset))
	row_i--;
      else
	{
	  row_offset += 1;
	  row_i = row_offset;
	  col_offset += 1;
	}
    }
  o->y = col_offset;
  o->x = row_i;
  calculate_coordinates(player, map, o);
}

void		vue_left(t_player *player, t_map *map, t_other *o)
{
  int		col_offset;
  int		row_offset;
  int		row_i;
  int		i;

  col_offset = -1;
  row_offset = (player->level);
  row_i = row_offset;
  i = 1;
  while (i != o->i)
    {
      i++;
      if (row_i > -(row_offset))
	row_i--;
      else
	{
	  row_offset += 1;
	  row_i = row_offset;
	  col_offset -= 1;
	}
    }
  o->y = row_i;
  o->x = col_offset;
  calculate_coordinates(player, map, o);
}
