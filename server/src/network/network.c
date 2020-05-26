/*
** network.c for  in /home/liegem/rendu/PSU_2015_zappy/zappy_network
** 
** Made by liegem
** Login   <liegem@epitech.net>
** 
** Started on  Tue Jun 14 12:25:53 2016 liegem
** Last update Fri Jun 24 10:38:05 2016 Matheo MSA
*/

#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "network.h"
#include "game.h"

void	read_socket(char **buff, int sock)
{
  char	line[4096];
  short	pass;

  pass = 0;
  bzero(line, 4096);
  while (strchr(line, '\n') == NULL)
    {
      bzero(line, 4096);
      if (read(sock, line, 1) == 0)
	return;
      if (pass >= 1
	  && (int) (strlen((*buff)) + strlen(line)) > (4096 * pass))
	{
	  if (((*buff) = realloc((*buff), 4096)) == NULL)
	    exit(EXIT_FAILURE);
	  pass++;
	}
      else
	pass = 1;
      strcat((*buff), line);
    }
}

int                     accept_client(int sock)
{
  struct sockaddr_in    a_sin;
  socklen_t             len;
  int                   asock;

  len = sizeof(a_sin);
  if ((asock = accept(sock, (struct sockaddr *) &a_sin, &len)) == -1)
    {
      if (write(2, "Accept new client failed.\n", 26))
	return (-1);
      return (-1);
    }
  if (dprintf(asock, "BIENVENUE\n"))
    return (asock);
  return (asock);
}

bool			select_sock(int sock, fd_set *rdfs,
				    t_fds **fds, t_game *game)
{
  struct timeval        tv;
  int			max;
  t_fds			*tmp;

  tmp = (*fds);
  tv.tv_sec = 0;
  tv.tv_usec = 1;
  FD_ZERO(rdfs);
  FD_SET(sock, rdfs);
  if ((max = set_fd_clients(tmp, rdfs)) == -1)
    max = sock;
  max = set_fd_players(game->teams, rdfs, max);
  max = set_fd_graph(game->fd_graph, rdfs, max);
  if (select(max + 1, rdfs, NULL, NULL, &tv) <= 0)
    return (false);
  return (true);
}
