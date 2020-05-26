/*
** ptr_actions.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Jun  8 15:01:16 2016 pallua_j
** Last update Mon Jun 13 17:27:55 2016 pallua_j
*/

#include "game.h"
#include "my.h"

bool		_msz_ptr(t_game *this, char **tab, int fd)
{
  (void)tab;
  size_map_graph(this, fd);
  return (true);
}

bool		_bct_ptr(t_game *this, char **tab, int fd)
{
  int		x;
  int		y;

  if (tab[1] != NULL && tab[2] != NULL)
    {
      if ((x = atoi(tab[1])) == 0 || x >= this->map->size_x)
	if (my_strcmp("0", tab[1]) != 0)
	  return (false);
      if ((y = atoi(tab[2])) == 0 || y >= this->map->size_y)
	if (my_strcmp("0", tab[2]) != 0)
	  return (false);
      print_case_graph(this, x, y, fd);
      return (true);
    }
  return (false);
}

bool		_mct_ptr(t_game *this, char **tab, int fd)
{
  (void)tab;
  print_map_graph(this, fd);
  return (true);
}

bool		_tna_ptr(t_game *this, char **tab, int fd)
{
  (void)tab;
  print_team_graph(this, fd);
  return (true);
}
