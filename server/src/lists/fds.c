/*
** fds.c for  in /home/liegem/rendu/PSU_2015_zappy/zappy_network
** 
** Made by liegem
** Login   <liegem@epitech.net>
** 
** Started on  Tue Jun 14 13:04:31 2016 liegem
** Last update Tue Jun 21 17:51:14 2016 toozs-_c
*/

#include <stdlib.h>
#include <unistd.h>
#include "fds.h"

int		set_fd_clients(t_fds *fds, fd_set *rdfs)
{
  t_fds		*tmp;
  int		max;

  if (fds == NULL)
    return (-1);
  tmp = fds;
  max = tmp->fd;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, rdfs);
      if (tmp->fd > max)
	max = tmp->fd;
      tmp = tmp->next;
    }
  return (max);
}

int		fds_push_back(t_fds **list, int fd)
{
  t_fds 	*block;
  t_fds 	*tmp;

  if ((block = malloc(sizeof(*block))) == NULL)
    return (1);
  block->fd = fd;
  block->next = NULL;
  if ((*list) == NULL)
    {
      block->prev = NULL;
      (*list) = block;
    }
  else
    {
      tmp = (*list);
      while ((*list)->next != NULL)
        (*list) = (*list)->next;
      (*list)->next = block;
      (*list)->next->prev = (*list);
      (*list) = tmp;
    }
  return (0);
}

void		fds_remove_node(t_fds **head, t_fds **node)
{
  t_fds		*tmp;

  tmp = (*node);
  if ((*node)->prev != NULL)
    (*node)->prev->next = (*node)->next;
  if ((*node)->next != NULL)
    (*node)->next->prev = (*node)->prev;
  if ((*node)->prev == NULL)
    (*head) = (*head)->next;
  (*node) = (*head);
  free(tmp);
}
