/*
** init_network.c for  in /home/liegem/rendu/PSU_2015_zappy/zappy_network
** 
** Made by liegem
** Login   <liegem@epitech.net>
** 
** Started on  Tue Jun 14 13:37:06 2016 liegem
** Last update Tue Jun 21 14:13:42 2016 toozs-_c
*/

#include "network.h"
#include "server.h"

void                    param_socket(struct sockaddr_in *sin, int port)
{
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  sin->sin_addr.s_addr = htonl(INADDR_ANY);
}

int                     open_socket(t_data *data)
{
  struct sockaddr_in	sin;

  param_socket(&sin, data->port);
  if ((bind(data->sock, (struct sockaddr *) &sin, sizeof(sin))) == -1)
    {
      close(data->sock);
      free_teams(data->teams);
      exit(1);
    }
  if ((listen(data->sock, 90000)) == -1)
    {
      close(data->sock);
      free_teams(data->teams);
      exit(1);
    }
  data_network(data);
  return (0);
}

void            reuse_socket(t_data *data)
{
  int           _true;

  _true = 1;
  if (setsockopt(data->sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &_true,
		 sizeof(int)) < 0)
    {
      close(data->sock);
      free_teams(data->teams);
      printf("setsockopt failed\n");
      exit(1);
    }
}

void	init_network(t_data *data)
{
  if ((data->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      close(data->sock);
      free_teams(data->teams);
      return;
    }
  reuse_socket(data);
  open_socket(data);
}
