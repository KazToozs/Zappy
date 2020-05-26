/*
** parameters.h for zappy in /home/toozs-_c/tek2/zappy_args/include
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun  7 11:56:21 2016 toozs-_c
** Last update Mon Jun 20 17:50:46 2016 toozs-_c
*/

#ifndef PARAMS_H_
#define PARAMS_H_

#include <stdio.h>
#include "team.h"

typedef struct	s_params
{
  int		ac;
  int		p;
  int		x;
  int		y;
  int		t;
  int		c;
  int		n;
}		t_params;

typedef struct	s_data
{
  int		sock;
  int		port;
  int		x;
  int		y;
  int		time;
  int		ccount;
  t_team       	*teams;
}		t_data;

typedef struct	s_option
{
  char		*option;
  int		(*ptr)(int, char **, t_params *, t_data *);
}		t_option;

typedef struct	s_option_s
{
  char		*option;
}		t_option_s;

void		print_usage(char *str);
int             check_args(int, char **, t_params *, t_data *);
int             all_parameters_met(t_params, t_data *);

int		check_p(int, char **, t_params *, t_data *);
int		check_x(int, char **, t_params *, t_data *);
int		check_y(int, char **, t_params *, t_data *);
int		check_n(int, char **, t_params *, t_data *);
int		check_c(int, char **, t_params *, t_data *);
int		check_t(int, char **, t_params *, t_data *);

void		free_data(t_data *);

#endif
