/*
** inventaire.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Jun  9 19:56:55 2016 toozs-_c
** Last update Mon Jun 20 16:42:17 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"

t_inv_print	g_print[] =
  {
    {NOURRITURE, "nourriture"},
    {LINEMATE, "linemate"},
    {DERAUMERE, "deraumere"},
    {SIBUR, "sibur"},
    {MENDIANE, "mendiane"},
    {PHIRAS, "phiras"},
    {THYSTAME, "thystame"},
    {NONE, NULL},
  };

void		print_inventaire(t_player *player, int *inventaire)
{
  int		i;

  i = 0;
  while (i != (int)NONE)
    {
      if (dprintf(player->client_fd, " %s %d", g_print[i].str, inventaire[i])
	  < 0)
	return ;
      i++;
      if (i != (int)NONE)
	if (dprintf(player->client_fd, ",") < 0)
	  return ;
    }
}

void		print_ca_ressources(t_player *player, t_case ca)
{
  int		i;
  t_playercase	*tmp;
  int		res_tmp;

  i = 0;
  tmp = ca.players;
  while (tmp != NULL)
    {
      if (dprintf(player->client_fd, " joueur") < 0)
	return ;
      tmp = tmp->next;
    }
  if (ca.ressources[0] > 0)
    if (dprintf(player->client_fd, " %s", g_print[0].str) < 0)
      return ;
  while (++i != (int)NONE)
    {
      res_tmp = ca.ressources[i] + 1;
      while (--res_tmp > 0)
	{
	  if (dprintf(player->client_fd, " %s", g_print[i].str) < 0)
	    return ;
	}
    }
}

e_resname		get_ressource(char *res_name)
{
  int			i;

  i = 0;
  while (i != (int)NONE)
    {
      if (!my_strcmp(res_name, g_print[i].str))
	return (g_print[i].res);
      i++;
    }
  return (NONE);
}
