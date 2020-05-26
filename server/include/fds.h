/*
** fds.h for zappy in /home/pallua_j/rendu/tmp/zappy/include
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Jun  7 17:15:27 2016 pallua_j
** Last update Tue Jun 14 13:15:55 2016 liegem
*/

#ifndef _FDS__H_
# define _FDS__H_

#include <sys/select.h>

typedef struct	s_fds
{
  struct s_fds	*prev;
  int		fd;
  struct s_fds	*next;
}		t_fds;

int		        fds_push_back(t_fds **, int fd);
void			fds_remove_node(t_fds **, t_fds **);
int			set_fd_clients(t_fds *, fd_set *rdfs);

#endif /*!_FDS__H_*/
