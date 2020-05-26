/*
** t_param.c for zappy in /home/toozs-_c/tek2/zappy_args/src/param_checks
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun  7 14:22:36 2016 toozs-_c
** Last update Thu Jun 23 17:16:39 2016 toozs-_c
*/

#include <stdlib.h>
#include <stdio.h>
#include "parameters.h"

int		check_t(int i, char **av, t_params *params, t_data *data)
{
  if (!params->t)
    {
      if (i >= params->ac)
	{
          print_usage("'-t': Delay must be between 0 and 1000");
	  return (-1);
	}
      data->time = atoi(av[i]);
      if (data->time == 0 || data->time > 1000)
        {
          print_usage("'-t': Delay must be between 0 and 1000");
          return (-1);
        }
      else if (data->time < 0)
	data->time *= -1;
      params->t = 1;
      return (i);
    }
  else
    {
      print_usage("Multiple deffinitions of '-t' parameter");
      return (-1);
    }
}
