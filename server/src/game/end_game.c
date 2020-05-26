/*
** end_game.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/server/src/gameloop
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Jun 20 16:43:09 2016 toozs-_c
** Last update Wed Jun 22 10:50:21 2016 toozs-_c
*/

#include <unistd.h>
#include "game.h"

void		close_fd(t_game *game)
{
  t_team	*tmpt;
  t_player	*tmp;
  t_fds		*g;

  tmpt = game->teams;
  while (tmpt)
    {
      tmp = tmpt->players;
      while (tmp)
	{
	  player_remove_node(&tmp, &tmp);
	}
      team_remove_node(&tmpt, &tmpt);
    }
  g = game->fd_graph;
  while (g)
    {
      if (close(g->fd) == -1)
	exit(1);
      fds_remove_node(&g, &g);
    }
}

void		check_end(t_game *game)
{
  t_team	*tmpt;
  t_player	*tmp;
  int		cpt;

  tmpt = game->teams;
  while (tmpt)
    {
      cpt = 0;
      tmp = tmpt->players;
      while (tmp)
	{
	  if (tmp->level == 8)
	    cpt++;
	  if (cpt >= 6)
	    {
	      _seg(game, tmpt->name);
	      close_fd(game);
	      exit(0);
	    }
	  tmp = tmp->next;
	}
      tmpt = tmpt->next;
    }
}
