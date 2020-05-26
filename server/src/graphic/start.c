/*
** start.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/server/src/graphic
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Jun 20 16:49:29 2016 toozs-_c
** Last update Wed Jun 22 11:48:17 2016 toozs-_c
*/

#include "game.h"

void		print_player(t_game *game, int fd)
{
  t_team	*tmpt;
  t_player	*tmp;

  tmpt = game->teams;
  while (tmpt)
    {
      tmp = tmpt->players;
      while (tmp)
	{
	  if (dprintf(fd, "pnw %d %d %d %d %d %s\n",
		      tmp->nb, tmp->pos.x, tmp->pos.y,
		      tmp->orientation, tmp->level, tmp->team_name) < 0)
	    tmp = tmp->next;
	  else
	    tmp = tmp->next;
	}
      tmpt = tmpt->next;
    }
}

void		print_egg(t_game *game, int fd)
{
  t_team	*tmpt;
  t_egg		*tmp;

  tmpt = game->teams;
  while (tmpt)
    {
      tmp = tmpt->eggs;
      while (tmp)
	{
	  if (dprintf(fd, "enw %d %d %d %d\n",
		      tmp->nb, tmp->nb_aut, tmp->pos.x, tmp->pos.y) < 0)
	    tmp = tmp->next;
	  else
	    tmp = tmp->next;
	}
      tmpt = tmpt->next;
    }
}

void start_graph(t_game *game, int fd)
{
  size_map_graph(game, fd);
  print_time_graph(game, fd);
  print_map_graph(game, fd);
  print_team_graph(game, fd);
  print_player(game, fd);
  print_egg(game, fd);
}
