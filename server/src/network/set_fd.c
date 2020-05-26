/*
** set_fd.c for  in /home/liegem/rendu/PSU_2015_zappy/server/src/network
**
** Made by liegem
** Login   <liegem@epitech.net>
**
** Started on  Wed Jun 15 14:48:41 2016 liegem
** Last update Fri Jun 24 11:37:47 2016 toozs-_c
*/

#include <string.h>
#include "network.h"
#include "game.h"
#include "player.h"

int             set_fd_players(t_team *team, fd_set *rdfs, int max)
{
  t_team	*tmp;
  t_player	*ptmp;

  if (team == NULL)
    return (max);
  tmp = team;
  while (tmp != NULL)
    {
      ptmp = tmp->players;
      while (ptmp != NULL)
	{
	  FD_SET(ptmp->client_fd, rdfs);
	  if (ptmp->client_fd > max)
	    max = ptmp->client_fd;
	  ptmp = ptmp->next;
	}
      tmp = tmp->next;
    }
  return (max);
}

int             set_fd_graph(t_fds *graph, fd_set *rdfs, int max)
{
  t_fds		*tmp;

  if (graph == NULL)
    return (max);
  tmp = graph;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, rdfs);
      if (tmp->fd > max)
	max = tmp->fd;
      tmp = tmp->next;
    }
  return (max);
}

bool		is_ghost_mode(t_player **player, int fd, t_game *game)
{
  t_player	*tmp;

  if ((tmp = (*player)) == NULL)
    return (false);
  while (tmp != NULL)
    {
      if (tmp->ghost == 1)
	{
	  tmp->ghost = 0;
	  tmp->client_fd = fd;
	  if (dprintf(fd, "%d\n%d %d\n",
		      game->ccount - get_ccount(game, tmp->team_name),
		      game->map->size_x, game->map->size_y) < 0)
	    return (false);
	  return (true);
	}
      tmp = tmp->next;
    }
  return (false);
}

bool		is_full_team(t_player *player, int ccount)
{
  t_player	*tmp;
  int		i;

  i = 0;
  if ((tmp = player) == NULL)
    return (false);
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  if (i == ccount)
    return (true);
  return (false);
}

bool		is_exist_team(char *str, t_fds **head,
			      t_fds *node, t_game *game)
{
  t_team	*tmp;

  tmp = game->teams;
  while (tmp != NULL)
    {
      if (!strcmp(tmp->name, str))
	{
	  if (!is_ghost_mode(&tmp->players, node->fd, game))
	    {
	      if (!is_full_team(tmp->players, game->ccount))
		player_push_back(&tmp->players, node->fd, game, tmp->name);
	      else
		if (close(node->fd) == -1)
		  exit(1);
	    }
	  fds_remove_node(head, &node);
	  return (true);
	}
      tmp = tmp->next;
    }
  return (false);
}
