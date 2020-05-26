/*
** list.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu May 19 18:06:47 2016 toozs-_c
** Last update Mon Jun 20 17:26:15 2016 toozs-_c
*/

#include <stdlib.h>
#include "team.h"
#include "my.h"

void		init_team(t_team *block, char *name)
{
  block->players = NULL;
  block->name = my_strdup(name);
  block->current_nb = 0;
  block->max_nb = 0;
  block->eggs = NULL;
}

int		team_push_back(t_team **list, char *name)
{
  t_team	*block;
  t_team	*tmp;

  if ((block = malloc(sizeof(*block))) == NULL)
    exit(1);
  init_team(block, name);
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

void			team_remove_node(t_team **head, t_team **node)
{
  t_team		*tmp;

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
