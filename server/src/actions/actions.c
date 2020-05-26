/*
** actions.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Jun  8 11:05:47 2016 toozs-_c
** Last update Tue Jun 21 17:27:27 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"
#include "my.h"

t_action_exec	g_actions_exec[] =
  {
    {AVANCE, &_avance},
    {DROITE, &_droite},
    {GAUCHE, &_gauche},
    {VOIR, &_voir},
    {INVENTAIRE, &_inventaire},
    {PREND, &_prend},
    {POSE, &_pose},
    {EXPULSE, &_expulse},
    {BROADCAST, &_broadcast},
    {INCANTATION, &_incantation},
    {FORK, &_fork},
    {CONNECT, &_connect_nb},
    {NOTHING, NULL}
  };

void		execute_action(char *str, t_player *player,
			       t_game *game)
{
  int		i;
  char		**tab;
  int		tabsize;

  i = 0;
  tab = my_str_tab(str);
  tabsize = tab_size(tab);
  while (g_actions_exec[i].action != player->action
	 && g_actions_exec[i].action != NOTHING)
    i++;
  if (g_actions_exec[i].action != NOTHING)
    g_actions_exec[i].ptr(tabsize, tab, player, game);
  free_tab(tab);
}
