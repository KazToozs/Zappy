/*
** playercase.c for zappy in /home/pallua_j/rendu/tmp/zappy/src
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Jun  7 13:45:57 2016 pallua_j
** Last update Fri Jun 24 13:52:31 2016 toozs-_c
*/

#include <stdlib.h>
#include "egg.h"
#include "game.h"
#include "my.h"

int		egg_count(t_egg *list)
{
  int		count;
  t_egg		*tmp;

  tmp = list;
  count = 0;
  while (tmp != NULL)
    {
      count++;
      tmp = tmp->next;
    }
  return (count);
}

void		init_egg(t_egg *block, t_pos pos, char *team_name)
{
  static int	nb_egg = 1000;

  block->pos = pos;
  block->time = 600;
  my_clock_gettime(&block->start);
  block->nb = nb_egg++;
  block->team_name = my_strdup(team_name);
}

int		egg_push_back(t_egg **list, t_pos pos, char *team_name)
{
  t_egg 	*block;
  t_egg 	*tmp;

  if ((block = malloc(sizeof(*block))) == NULL)
    return (1);
  block->next = NULL;
  init_egg(block, pos, team_name);
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

void		egg_remove_node(t_egg **head, t_egg **node)
{
  t_egg		*tmp;

  tmp = (*node);
  if ((*node)->prev != NULL)
    (*node)->prev->next = (*node)->next;
  if ((*node)->next != NULL)
    (*node)->next->prev = (*node)->prev;
  if ((*node)->prev == NULL)
    (*head) = (*head)->next;
  (*node) = (*head);
  if (tmp->team_name)
    free(tmp->team_name);
  free(tmp);
}
