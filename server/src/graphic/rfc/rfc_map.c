/*
** rfc_map.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Jun  8 10:20:10 2016 pallua_j
** Last update Wed Jun 22 10:42:00 2016 toozs-_c
*/

#include "game.h"

void		_msz(t_game *this)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      size_map_graph(this, tmp->fd);
      tmp = tmp->next;
    }
}

void		_bct(t_game *this, int x, int y)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      print_case_graph(this, x, y, tmp->fd);
      tmp = tmp->next;
    }
}

void		_tna(t_game *this)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      print_team_graph(this, tmp->fd);
      tmp = tmp->next;
    }
}

void		_mct(t_game *this)
{
  int		x;
  int		y;

  x = 0;
  while (x < this->map->size_x)
    {
      y = 0;
      while (y < this->map->size_y)
        {
          _bct(this, x, y);
          y++;
        }
      x++;
    }
}
