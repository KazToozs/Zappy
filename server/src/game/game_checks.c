/*
** game_checks.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/server/src/gameloop
**
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
**
** Started on  Fri Jun 17 11:33:53 2016 toozs-_c
** Last update Fri Jun 24 13:51:38 2016 toozs-_c
*/

#include <time.h>
#include "game.h"

int			set_food(t_player *player, t_game *game)
{
  struct timespec	curr;
  double		delta;

  my_clock_gettime(&curr);
  delta = ((double)curr.tv_sec + 1.0e-9 * curr.tv_nsec) -
    ((double)player->start.tv_sec + 1.0e-9 * player->start.tv_nsec);
  player->life -= delta * (double)game->game_delay;
  player->start = curr;
  if (player->life > 0)
    {
      player->inventaire[0] = (int)player->life / 126;
      return (0);
    }
  else
    return (1);
}

void		check_food(t_game *game)
{
  t_team	*ttmp;
  t_player	*ptmp;

  ttmp = game->teams;
  while (ttmp != NULL)
    {
      ptmp = ttmp->players;
      while (ptmp != NULL)
	{
	  if (set_food(ptmp, game))
	    {
	      _pdi(game, ptmp);
	      if (ptmp->ghost == 0)
		if (dprintf(ptmp->client_fd, "mort\n") < 0)
		  continue ;
	      remove_pl_from_case(ptmp,
				  &game->map->mp[ptmp->pos.x][ptmp->pos.y]);
	      player_remove_node(&ttmp->players, &ptmp);
	    }
	  if (ptmp != NULL)
	    ptmp = ptmp->next;
	}
      ttmp = ttmp->next;
    }
}

int			set_egg(t_egg *egg, t_game *game)
{
  struct timespec	curr;
  double		delta;

  my_clock_gettime(&curr);
  delta = ((double)curr.tv_sec + 1.0e-9 * curr.tv_nsec) -
    ((double)egg->start.tv_sec + 1.0e-9 * egg->start.tv_nsec);
  egg->time -= delta * (double)game->game_delay;
  egg->start = curr;
  if (egg->time > 0)
    return (0);
  else
    return (1);
}

void		set_egg_player(t_player **players, t_egg *egg, t_game *game)
{
  t_player	*ptmp;
  t_player	*mark;

  ptmp = (*players)->next;
  mark = *players;
  while (ptmp != NULL)
    {
      mark = mark->next;
      ptmp = ptmp->next;
    }
  if (mark != NULL)
    {
      mark->pos.x = egg->pos.x;
      mark->pos.y = egg->pos.y;
      _pnw(game, mark);
      case_push_back(&game->map->mp[mark->pos.x][mark->pos.y].players, mark);
    }
}

void		check_eggs(t_game *game)
{
  t_team	*ttmp;
  t_egg		*etmp;

  ttmp = game->teams;
  while (ttmp != NULL)
    {
      etmp = ttmp->eggs;
      while (etmp != NULL)
	{
	  if (set_egg(etmp, game))
	    {
	      player_push_back_ghost(&ttmp->players, -1, game, ttmp->name);
	      set_egg_player(&ttmp->players, etmp, game);
	      _eht(game, etmp);
	      egg_remove_node(&ttmp->eggs, &etmp);
	      break ;
	    }
	  etmp = etmp->next;
	}
      ttmp = ttmp->next;
    }
}
