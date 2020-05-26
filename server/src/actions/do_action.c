/*
** do_action.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/server/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Jun 16 13:33:42 2016 toozs-_c
** Last update Fri Jun 24 13:50:08 2016 toozs-_c
*/

#include <time.h>
#include "actions.h"

int			action_is_ready(t_player *player, t_game *game)
{
  double		delta;
  struct timespec	curr;

  my_clock_gettime(&curr);
  delta = ((double)curr.tv_sec + 1.0e-9 * curr.tv_nsec) -
    ((double)player->timer.tv_sec + 1.0e-9 * player->timer.tv_nsec);
  player->delay -= delta * (double)game->game_delay;
  player->timer = curr;
  if (player->delay <= 0)
    return (1);
  else
    return (0);
}

int		get_new_action(t_player *player, t_game *game)
{
  char		**tab;

  if (player->queue == NULL)
    return (1);
  tab = my_str_tab(player->queue->cmd);
  set_timer(tab_size(tab), tab, player, game);
  free_tab(tab);
  return (0);
}

int		do_action(t_game *game)
{
  t_team	*ttmp;
  t_player	*ptmp;

  ttmp = game->teams;
  while (ttmp != NULL)
    {
      ptmp = ttmp->players;
      while (ptmp != NULL)
	{
	  if (ptmp->action != NOTHING)
	    {
	      if (action_is_ready(ptmp, game))
		{
		  execute_action(ptmp->queue->cmd, ptmp, game);
		  cmd_remove_node(&ptmp->queue, &ptmp->queue);
		  ptmp->action = NOTHING;
		}
	    }
	  else
	    get_new_action(ptmp, game);
	  ptmp = ptmp->next;
	}
      ttmp = ttmp->next;
    }
  return (0);
}
