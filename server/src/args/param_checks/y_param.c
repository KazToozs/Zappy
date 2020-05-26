/*
** param_checkers.c for zappy in /home/toozs-_c/tek2/zappy_args/src
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun  7 12:31:08 2016 toozs-_c
** Last update Wed Jun 15 16:53:11 2016 toozs-_c
*/

#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"

int		check_y(int i, char **av, t_params *params, t_data *data)
{
  if (!params->y)
    {
      params->y = 1;
      if (i >= params->ac)
        {
          print_usage("'-y': Map dimension too small");
          return (-1);
        }
      data->y = atoi(av[i]);
      if (data->y <= 0)
	{
          print_usage("'-y': Map dimension too small");
          return (-1);
        }
      return (i);
    }
  else
    {
      print_usage("Multiple definitions of '-y' parameter");
      return (-1);
    }
}
