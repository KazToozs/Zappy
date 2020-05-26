/*
** rfc_time.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Jun  8 11:41:21 2016 pallua_j
** Last update Wed Jun 22 10:44:56 2016 toozs-_c
*/

#include "game.h"

void		_sgt(t_game *this)
{
  t_fds		*tmp;

  tmp = this->fd_graph;
  while (tmp)
    {
      print_time_graph(this, tmp->fd);
      tmp = tmp->next;
    }
}

void		print_time_graph(t_game *this, int fd)
{
  if (dprintf(fd, "sgt %d\n", this->game_delay) < 0)
    return ;
}

void		change_time_graph(t_game *this, int value, int fd)
{
  this->game_delay = value;
  print_time_graph(this, fd);
}
