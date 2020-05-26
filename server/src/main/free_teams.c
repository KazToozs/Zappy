/*
** free_teams.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/server/src
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun 21 15:21:02 2016 toozs-_c
** Last update Tue Jun 21 15:30:25 2016 toozs-_c
*/

#include <errno.h>
#include <unistd.h>
#include "server.h"

void		free_cmds(t_cmd *cmds)
{
  t_cmd		*tmp;

  if (cmds != NULL)
    {
      tmp = cmds;
      cmds = cmds->next;
      while (tmp != NULL)
        {
          if (tmp->cmd)
            free(tmp->cmd);
          free(tmp);
          tmp = cmds;
          if (cmds)
            cmds = cmds->next;
	}
    }
}

void		free_player(t_player *players)
{
  t_player	*tmp;

  if (players != NULL)
    {
      tmp = players;
      players = players->next;
      while (tmp != NULL)
        {
          if (tmp->team_name)
            free(tmp->team_name);
          free_cmds(tmp->queue);
          if (close(tmp->client_fd) == -1 && errno != 9)
            exit(1);
          free(tmp);
          tmp = players;
          if (players)
            players = players->next;
        }
    }
}

void		free_eggs(t_egg *eggs)
{
  t_egg		*tmp;

  if (eggs != NULL)
    {
      tmp = eggs;
      eggs = eggs->next;
      while (tmp != NULL)
        {
          if (tmp->team_name)
            free(tmp->team_name);
          free(tmp);
          tmp = eggs;
          if (eggs)
            eggs = eggs->next;
        }
    }
}

void		free_teams(t_team *teams)
{
  t_team	*tmp;

  if (teams == NULL)
    return ;
  tmp = teams;
  teams = teams->next;
  while (tmp != NULL)
    {
      if (tmp->name)
        free(tmp->name);
      free_player(tmp->players);
      free_eggs(tmp->eggs);
      free(tmp);
      tmp = teams;
      if (teams)
        teams = teams->next;
    }
}
