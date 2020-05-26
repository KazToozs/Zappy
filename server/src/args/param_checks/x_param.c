/*
** x_param.c for zappy in /home/toozs-_c/tek2/zappy_args/src/param_checks
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun  7 14:12:20 2016 toozs-_c
** Last update Wed Jun 15 16:53:25 2016 toozs-_c
*/

#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"

int		check_x(int i, char **av, t_params *params, t_data *data)
{
  if (!params->x)
    {
      params->x = 1;
      if (i >= params->ac)
        {
          print_usage("'-x': Map dimension too small");
          return (-1);
        }
      data->x = atoi(av[i]);
      if (data->x <= 0 || data->x > 100)
	{
	  print_usage("'-x': Map dimension too small");
	  return (-1);
	}
      return (i);
    }
  else
    {
      print_usage("Multiple definitions of '-x' parameter");
      return (-1);
    }
}
