/*
** manage.c for  in /home/liegem/rendu/PSU_2015_zappy/zappy_network
**
** Made by liegem
** Login   <liegem@epitech.net>
**
** Started on  Tue Jun 14 15:34:12 2016 liegem
** Last update Wed Jun 22 18:14:27 2016 liegem
*/

#include <string.h>
#include "network.h"

bool	is_disconnect(char *str, t_fds **tmp, t_fds **fds)
{
  if (strlen(str) == 0)
    {
      if (close((*fds)->fd) == -1)
	exit(1);
      fds_remove_node(fds, tmp);
      free(str);
      return (true);
    }
  return (false);
}

bool	is_graph_disconnect(char *str, t_fds **graph, t_fds **head)
{
  if (strlen(str) == 0)
    {
      if (close((*graph)->fd) == -1)
	exit(1);
      fds_remove_node(head, graph);
      free(str);
      return (true);
    }
  return (false);
}

bool	is_player_disconnect(char *str, t_player **player, t_player **head)
{
  (void) head;
  if (strlen(str) == 0)
    {
      printf("Disconnect : %d\n", (*player)->client_fd);
      if (close((*player)->client_fd) == -1)
	exit(1);
      (*player)->client_fd = -1;
      (*player)->ghost = 1;
      free(str);
      return (true);
    }
  return (false);
}

void		manage_clients(char *str, t_fds **head,
			       t_fds *node, t_game *game)
{
  if (is_exist_team(str, head, node, game))
    return;
  if (!strcmp(GRAPH, str))
  {
    start_graph(game, node->fd);
    fds_push_back(&game->fd_graph, node->fd);
    fds_remove_node(head, &node);
    return ;
  }
  close(node->fd);
  fds_remove_node(head, &node);
}

bool	is_cmd_full(t_cmd *cmd)
{
  t_cmd	*tmp;
  int	i;

  i = 0;
  if (cmd == NULL)
    return (false);
  tmp = cmd;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  if (i >= 10)
    return (true);
  return (false);
}
