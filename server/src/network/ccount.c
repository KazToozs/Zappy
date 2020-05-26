/*
** ccount.c for zappy in /Users/pallua_j/rendu/PSU_2015_zappy/server/src/network/
**
** Made by Jules Palluau
** Login   <pallua_j@epitech.eu>
**
** Started on  Thu Jun 23 11:26:37 2016 Jules Palluau
** Last update Thu Jun 23 11:31:28 2016 Jules Palluau
*/

#include <string.h>
#include "game.h"

int		get_ccount(t_game *game, char *name)
{
  int		ret;
  t_team	*tmp;
  t_player	*ptmp;

  ret = 0;
  tmp = game->teams;
  while (tmp)
    {
      if (!strcmp(name, tmp->name))
	{
	  ptmp = tmp->players;
	  while (ptmp)
	    {
	      ret += 1;
	      ptmp = ptmp->next;
	    }
	}
      tmp = tmp->next;
    }
  return (ret);
}
