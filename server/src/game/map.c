/*
** map.c for zappy in /home/pallua_j/rendu/tmp/zappy/src
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Jun  7 13:56:21 2016 pallua_j
** Last update Fri Jun 24 15:19:49 2016 Matheo MSA
*/

#include <stdio.h>
#include "map.h"

static void	alloc_map(t_map *this)
{
  int		cpt;

  cpt = 0;
  if ((this->mp = malloc(sizeof(t_case *) * (this->size_x + 1))) == NULL)
    exit(-1);
  while (cpt < this->size_x)
    {
      if ((this->mp[cpt] = malloc(sizeof(t_case) * (this->size_y))) == NULL)
	exit(-1);
      cpt++;
    }
  this->mp[cpt] = NULL;
}

static t_case	random_case(t_case this)
{
  e_resname	name;

  if (rand() % 2 != 0)
    {
      if (rand() % 25 == 0)
	name = THYSTAME;
      else
	name = rand() % NBREF;
    }
  else
    name = NOURRITURE;
  this.ressources[name] += 1;
  return (this);
}

static t_case	generate_case(t_case this, int max_res, int x, int y)
{
  int		cpt;
  int		nb_res;

  cpt = 0;
  while (cpt < NBREF + 1)
    this.ressources[cpt++] = 0;
  this.pos.x = x;
  this.pos.y = y;
  cpt = 0;
  this.players = NULL;
  if ((rand() % 3) != 0)
    {
      nb_res = rand() % max_res;
      nb_res += 1;
      while (cpt < nb_res)
	{
	  this = random_case(this);
	  cpt++;
	}
    }
  return (this);
}

static void	create_map(t_map *this)
{
  int		x;
  int		y;
  int		max_res;

  x = 0;
  max_res = (this->size_x + this->size_y) / 2;
  if (max_res > 5)
    max_res = 5;
  srand(time(NULL));
  while (x < this->size_x)
    {
      y = 0;
      while (y < this->size_y)
	{
	  this->mp[x][y] = generate_case(this->mp[x][y], max_res, x, y);
	  y++;
	}
      x++;
    }
}

t_map		*generate_map(int size_x, int size_y)
{
  t_map		*map;

  if ((map = malloc(sizeof(t_map))) == NULL)
    exit(-1);
  map->size_x = size_x;
  map->size_y = size_y;
  alloc_map(map);
  create_map(map);
  return (map);
}
