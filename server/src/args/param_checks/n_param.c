/*
** n_param.c for zappy in /home/toozs-_c/tek2/zappy_args/src/param_checks
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun  7 14:46:18 2016 toozs-_c
** Last update Wed Jun 22 11:53:00 2016 toozs-_c
*/

#include "parameters.h"
#include "my.h"

static t_option_s g_options_s[] =
  {
    {"-p"},
    {"-x"},
    {"-y"},
    {"-c"},
    {"-t"},
    {"-n"},
    {NULL}
  };

int		check_existing_teams(char *name, t_team *teams)
{
  t_team	*tmp;
  int		found;

  tmp = teams;
  found = 0;
  while (found == 0 && tmp != NULL)
    {
      if (!my_strcmp(tmp->name, name))
	{
	  found = 1;
	}
      tmp = tmp->next;
    }
  if (found == 1)
    {
      print_usage("'-n' multiple teams of the same name given");
      return (-1);
    }
  return (0);
}

int		is_option(int i, int n, int count, char **av)
{
  if (!my_strcmp(g_options_s[n].option, av[i]))
    {
      if (count < 2)
	{
	  print_usage("'-n' Not enough teams given");
	  return (-1);
	}
      return (i);
    }
  return (0);
}

int		multiple_n()
{
  print_usage("Multiple definition of '-n' parameter");
  return (-1);
}

int		get_names(int i, char **av, t_params *params, t_data *data)
{
  int		count;
  int		ret;
  int		n;

  count = 0;
  while (i < params->ac)
    {
      n = -1;
      while (g_options_s[++n].option != NULL)
	{
	  if ((ret = is_option(i, n, count, av)))
	    return (ret);
	}
      if ((ret = check_existing_teams(av[i], data->teams)))
	return (ret);
      team_push_back(&data->teams, av[i]);
      count++;
      i++;
    }
  if (count < 2)
    {
      print_usage("'-n' Not enough teams given");
      return (-1);
    }
  return (i);
}

int		check_n(int i, char **av, t_params *params, t_data *data)
{
  if (!params->n)
    {
      params->n = 1;
      return (get_names(i, av, params, data));
    }
  return (multiple_n());
}
