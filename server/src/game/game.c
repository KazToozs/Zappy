/*
** game.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Jun  7 17:29:21 2016 pallua_j
** Last update Fri Jun 24 11:06:49 2016 toozs-_c
*/

#include "server.h"

void		add_food(t_game *game)
{
  int		x;
  int		y;

  x = 0;
  while (x < game->map->size_x)
    {
      y = 0;
      while (y < game->map->size_y)
        {
          if (rand() % 8)
            game->map->mp[x][y].ressources[0] += 1;
          y++;
        }
      x++;
    }
}

t_game		*create_game(t_data *data)
{
  t_game	*this;
  t_team	*tmp;

  if ((this = malloc(sizeof(t_game))) == NULL)
    {
      free_teams(data->teams);
      exit(1);
    }
  this->game_delay = data->time;
  this->map = generate_map(data->x, data->y);
  this->teams = data->teams;
  this->fd_graph = NULL;
  this->ccount = data->ccount;
  tmp = this->teams;
  while (tmp)
    {
      tmp->max_nb = data->ccount;
      tmp = tmp->next;
    }
  return (this);
}
