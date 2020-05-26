/*
** ptr_time.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Jun  8 16:04:00 2016 pallua_j
** Last update Mon Jun 13 17:26:48 2016 pallua_j
*/

#include "game.h"

bool		_sgt_ptr(t_game *this, char **tab, int fd)
{
  (void)tab;
  print_time_graph(this, fd);
  return (true);
}

bool		_sst_ptr(t_game *this, char **tab, int fd)
{
  int		time;

  if (tab[1] != NULL)
    {
      if ((time = atoi(tab[1])) == 0)
	return (false);
      change_time_graph(this, time, fd);
      return (true);
    }
  return (false);
}
