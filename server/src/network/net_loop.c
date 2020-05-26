/*
** net_loop.c for  in /home/liegem/rendu/PSU_2015_zappy/server/src/network
** 
** Made by liegem
** Login   <liegem@epitech.net>
** 
** Started on  Wed Jun 15 13:42:37 2016 liegem
** Last update Fri Jun 24 11:37:02 2016 toozs-_c
*/

#include <string.h>
#include "network.h"
#include "server.h"

t_ptrs		g_ptrs;

void            data_network(t_data *data)
{
  fd_set	rdfs;
  int		asock;

  g_ptrs.fds = NULL;
  g_ptrs.game = create_game(data);
  manage_signal();
  while (42)
    {
      if (select_sock(data->sock, &rdfs, &g_ptrs.fds, g_ptrs.game))
	{
	  if (FD_ISSET(data->sock, &rdfs))
	    {
	      asock = accept_client(data->sock);
	      fds_push_back(&g_ptrs.fds, asock);
	    }
	  check_graph(&rdfs, g_ptrs.game);
	  check_player(&rdfs, g_ptrs.game);
	  check_client(&g_ptrs.fds, &rdfs, g_ptrs.game);
	}
      check_food(g_ptrs.game);
      do_action(g_ptrs.game);
      check_eggs(g_ptrs.game);
    }
  free_ptrs(&g_ptrs);
}

void		check_client(t_fds **fds, fd_set *rdfs, t_game *game)
{
  t_fds		*tmp;
  char		*str;

  if ((tmp = (*fds)) == NULL)
    return;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, rdfs))
	{
	  if ((str = calloc(sizeof(char), sizeof(char) * 4096)) == NULL)
	    return;
	  read_socket(&str, tmp->fd);
	  if (is_disconnect(str, &tmp, fds))
	    break;
	  str[strlen(str) - 1] = 0;
	  manage_clients(str, fds, tmp, game);
	  free(str);
	  break;
	}
      tmp = tmp->next;
    }
}

int		loop_player(t_player **player, fd_set *rdfs)
{
  t_player	*tmp;
  char		*str;

  if ((*player) == NULL)
    return (false);
  tmp = (*player);
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->client_fd, rdfs))
	{
	  if ((str = calloc(sizeof(char), sizeof(char) * 4096)) == NULL)
	    return (false);
	  read_socket(&str, tmp->client_fd);
	  if (is_player_disconnect(str, &tmp, player))
	    return (true);
	  str[strlen(str) - 1] = 0;
	  if (!is_cmd_full(tmp->queue))
	    cmd_push_back(&tmp->queue, str);
	  free(str);
	}
      tmp = tmp->next;
    }
  return (false);
}

void		check_player(fd_set *rdfs, t_game *game)
{
  t_team	*tmp;
  t_player	*ptmp;

  if ((tmp = game->teams) == NULL)
    return;
  while (tmp != NULL)
    {
      ptmp = tmp->players;
      loop_player(&ptmp, rdfs);
      tmp = tmp->next;
    }
}

void		check_graph(fd_set *rdfs, t_game *game)
{
  t_fds		*tmp;
  char		*str;

  if ((tmp = game->fd_graph) == NULL)
    return;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, rdfs))
	{
	  if ((str = calloc(sizeof(char), sizeof(char) * 4096)) == NULL)
	    {
	      free_ptrs(&g_ptrs);
	      exit(1);
	    }
	  read_socket(&str, tmp->fd);
	  if (is_graph_disconnect(str, &tmp, &game->fd_graph))
	    break;
	  str[strlen(str) - 1] = 0;
	  do_graph_action(game, str, tmp->fd);
	  free(str);
	}
      tmp = tmp->next;
    }
}
