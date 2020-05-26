/*
** main.c for zappy in /home/toozs-_c/tek2/zappy_args
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun  7 11:32:14 2016 toozs-_c
** Last update Wed Jun 22 11:52:37 2016 toozs-_c
*/

#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"
#include "my.h"

static t_option g_options[] =
  {
    {"-p", &check_p},
    {"-x", &check_x},
    {"-y", &check_y},
    {"-n", &check_n},
    {"-c", &check_c},
    {"-t", &check_t},
    {NULL, NULL}
  };

void		set_params(t_params *para, int ac)
{
  para->ac = ac;
  para->p = 0;
  para->x = 0;
  para->y = 0;
  para->n = 0;
  para->c = 0;
  para->t = 0;
}

int		check_options(int *i, char **av,
			      t_params *params, t_data *data)
{
  int		n;

  n = -1;
  while (g_options[++n].option != NULL)
    {
      if (!my_strcmp(av[*i], g_options[n].option))
	{
	  if ((*i + 1) > params->ac)
	    {
	      print_usage("Missing parameter data");
	      return (1);
	    }
	  if ((*i = g_options[n].ptr(*i + 1, av, params, data)) > params->ac
	      || *i == -1)
	    return (1);
	  else
	    n = -1;
	}
    }
  return (0);
}

int		check_args(int ac, char **av, t_params *params, t_data *data)
{
  int		i;

  i = 1;
  set_params(params, ac);
  while (i < ac)
    {
      if (check_options(&i, av, params, data))
	return (1);
      i++;
    }
  return (0);
}

void		print_usage(char *str)
{
  if (fprintf(stderr, "%s\n", str) < 0)
    exit(1);
  if (fprintf(stderr,
	      "Usage: ./zappy_server -p [port] -x [map x] -y [map y]\n") < 0)
    exit(1);
  if (fprintf(stderr,
	      "                      -n [team name 1] [team name 2...]\n") < 0)
    exit(1);
  if (fprintf(stderr,
	      "                      -c [max clients] -t [delay]\n") < 0)
    exit(1);
}

int		all_parameters_met(t_params params, t_data *data)
{
  if (printf("p: %d x: %d y: %d c: %d n: %d\n", params.p,
	     params.x, params.y, params.c, params.n) < 0)
    return (1);
  if (!params.p || !params.x || !params.y
      || !params.c || !params.n)
    {
      print_usage("Missing parameters");
      return (1);
    }
  if (!params.t)
    {
      data->time = 100;
    }
  return (0);
}
