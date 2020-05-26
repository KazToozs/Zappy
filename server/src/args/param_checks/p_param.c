/*
** p_param.c for zappy in /home/toozs-_c/tek2/zappy_args/src/param_checks
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun  7 14:44:04 2016 toozs-_c
** Last update Wed Jun  8 10:34:32 2016 toozs-_c
*/

#include <stdlib.h>
#include <stdio.h>
#include "parameters.h"

int		check_p(int i, char **av, t_params *params, t_data *data)
{
  if (!params->p)
    {
      params->p = 1;
      if (i >= params->ac)
        {
          print_usage("'-p': invalid port");
          return (-1);
        }
      data->port = atoi(av[i]);
      if (data->port <= 0)
        {
          print_usage("'-p': invalid port");
          return (-1);
        }
      return (i);
    }
  else
    {
      print_usage("Multiple definitions of '-p' parameter");
      return (-1);
    }
}
