/*
** free_ptrs.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/server/src
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun 21 13:28:44 2016 toozs-_c
** Last update Wed Jun 22 11:37:17 2016 toozs-_c
*/

#include <unistd.h>
#include <errno.h>
#include "server.h"

void		free_playercase(t_playercase *players)
{
  t_playercase	*tmp;

  if (players != NULL)
    {
      tmp = players;
      players = players->next;
      while (tmp != NULL)
	{
	  free(tmp);
	  tmp = players;
	  if (players)
	    players = players->next;
	}
    }
}

void		free_map(t_map *map)
{
  int		x;
  int		y;

  x = -1;
  while (++x < map->size_x)
    {
      y = -1;
      while (++y < map->size_y)
	{
	  free_playercase(map->mp[x][y].players);
	}
      free(map->mp[x]);
    }
  free(map->mp);
  free(map);
}

void		free_game(t_game *game)
{
  t_fds		*tmp;

  free_teams(game->teams);
  free_map(game->map);
  if (game->fd_graph == NULL)
    {
      free(game);
      return ;
    }
  tmp = game->fd_graph;
  game->fd_graph = game->fd_graph->next;
  while (tmp != NULL)
    {
      if (close(tmp->fd) == -1 && errno != 9)
	exit(1);
      free(tmp);
      tmp = game->fd_graph;
      if (game->fd_graph)
        game->fd_graph = game->fd_graph->next;
    }
  free(game);
}

void		free_ptrs(t_ptrs *ptrs)
{
  t_fds		*tmp;

  free_game(ptrs->game);
  if (ptrs->fds == NULL)
    return ;
  tmp = ptrs->fds;
  ptrs->fds = ptrs->fds->next;
  while (tmp != NULL)
    {
      if (close(tmp->fd) == -1 && errno != 9)
	exit(1);
      free(tmp);
      tmp = ptrs->fds;
      if (ptrs->fds)
        ptrs->fds = ptrs->fds->next;
    }
}
