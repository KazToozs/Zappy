/*
** c_param.c for zappy in /home/toozs-_c/tek2/zappy_args/src/param_checks
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun  7 14:47:25 2016 toozs-_c
** Last update Tue Jun  7 18:57:39 2016 toozs-_c
*/

#include <stdlib.h>
#include <stdio.h>
#include "parameters.h"

int		check_c(int i, char **av, t_params *params, t_data *data)
{
  if (!params->c)
    {
      params->c = 1;
      data->ccount = atoi(av[i]);
      if (data->ccount <= 0)
        {
          print_usage("'-c': initial client max count too small");
          return (-1);
	}
      return (i);
    }
  else
    {
      print_usage("Multiple definitions of '-c' parameter");
      return (-1);
    }
}
