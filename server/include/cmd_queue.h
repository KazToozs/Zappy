/*
** cmd_queue.h for  in /home/liegem/rendu/PSU_2015_zappy/server/include
** 
** Made by liegem
** Login   <liegem@epitech.net>
** 
** Started on  Wed Jun 15 13:28:15 2016 liegem
** Last update Wed Jun 15 13:30:14 2016 liegem
*/

#ifndef _CMD__H_
# define _CMD__H_

#include <sys/select.h>

typedef struct	s_cmd
{
  struct s_cmd	*prev;
  char		*cmd;
  struct s_cmd	*next;
}		t_cmd;

int		        cmd_push_back(t_cmd **, char *cmd);
void			cmd_remove_node(t_cmd **, t_cmd **);

#endif /*!_CMD__H_*/
