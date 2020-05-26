/*
** cmd_queue.c for  in /home/liegem/rendu/PSU_2015_zappy/server/src/network
** 
** Made by liegem
** Login   <liegem@epitech.net>
** 
** Started on  Wed Jun 15 13:24:06 2016 liegem
** Last update Tue Jun 21 17:24:10 2016 toozs-_c
*/

#include <stdlib.h>
#include <string.h>
#include "cmd_queue.h"

int		cmd_push_back(t_cmd **list, char *cmd)
{
  t_cmd 	*block;
  t_cmd 	*tmp;

  if ((block = malloc(sizeof(*block))) == NULL)
    return (1);
  block->cmd = strdup(cmd);
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

void		cmd_remove_node(t_cmd **head, t_cmd **node)
{
  t_cmd		*tmp;

  tmp = (*node);
  if ((*node)->prev != NULL)
    (*node)->prev->next = (*node)->next;
  if ((*node)->next != NULL)
    (*node)->next->prev = (*node)->prev;
  if ((*node)->prev == NULL)
    (*head) = (*head)->next;
  (*node) = (*head);
  if (tmp->cmd)
    free(tmp->cmd);
  free(tmp);
}
