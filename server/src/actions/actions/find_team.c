/*
** find_team.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sat Jun 11 10:56:11 2016 toozs-_c
** Last update Sat Jun 11 11:08:36 2016 toozs-_c
*/

#include "actions.h"

t_team		*find_team(t_player *player, t_team *teams)
{
  t_team	*tmp;

  tmp = teams;
  while (tmp != NULL)
    {
      if (!my_strcmp(tmp->name, player->team_name))
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
