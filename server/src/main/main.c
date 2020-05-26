/*
** main.c for  in /home/liegem/rendu/PSU_2015_zappy/server/src
** 
** Made by liegem
** Login   <liegem@epitech.net>
** 
** Started on  Wed Jun 15 12:28:49 2016 liegem
** Last update Tue Jun 21 14:06:43 2016 toozs-_c
*/

#include "parameters.h"
#include "network.h"
#include "server.h"

int		main(int ac, char **av)
{
  t_data	data;
  t_params	params;

  if (ac > 1)
    {
      data.teams = NULL;
      if (check_args(ac, av, &params, &data))
	{
	  free_teams(data.teams);
	  return (1);
	}
      else if (all_parameters_met(params, &data))
	{
	  free_teams(data.teams);
	  return (1);
	}
      else
	init_network(&data);
    }
  else
    {
      print_usage("Missing parameters");
      return (1);
    }
  return (0);
}
