/*
** playercase.c for zappy in /home/pallua_j/rendu/tmp/zappy/src
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Jun  7 13:45:57 2016 pallua_j
** Last update Wed Jun 22 11:30:23 2016 toozs-_c
*/

#include "map.h"

int		case_push_back(t_playercase **list, t_player *pl)
{
  t_playercase 	*block;
  t_playercase 	*tmp;

  if ((block = malloc(sizeof(*block))) == NULL)
    exit(1);
  block->next = NULL;
  block->player = pl;
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

void		case_remove_node(t_playercase **head,
				 t_playercase **node)
{
  t_playercase	*tmp;

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
