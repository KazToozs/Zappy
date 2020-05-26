/*
** a_voir.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/zappy_actions/src/actions
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Jun  9 12:10:00 2016 toozs-_c
** Last update Thu Jun 16 11:41:44 2016 toozs-_c
*/

#include <stdio.h>
#include "actions.h"

t_dir_act	g_dir_vue[] =
  {
    {NORD, &vue_up},
    {EST, &vue_right},
    {SUD, &vue_down},
    {OUEST, &vue_left},
    {UNKNOWN, NULL}
  };

int		calculate_view_size(int level)
{
  int		size;
  int		i;

  if (level >= 1)
    {
      size = level + 1;
      i = 1;
      while (i <= level)
	{
	  size += (2 * i);
	  i++;
	}
      return (size);
    }
  else
    if (printf("Error: Player has an invalid level value. 'Voir' failed.\n")
	< 0)
      return (-1);
  return (-1);
}

t_case		find_case(int case_i, t_map *map, t_player *player)
{
  int		i;
  t_other	o;

  i = 0;
  o.i = case_i;
  o.x = -1;
  o.y = -1;
  while (g_dir_vue[i].dir != UNKNOWN
	 && g_dir_vue[i].dir != player->orientation)
    i++;
  if (g_dir_vue[i].dir != UNKNOWN)
    g_dir_vue[i].ptr(player, map, &o);
  return (map->mp[o.x][o.y]);
}

void		print_cases(t_player *player, t_case *cases, int nb_cases)
{
  int		i;

  i = -1;
  if (dprintf(player->client_fd, "{") < 0)
    return ;
  while (++i < nb_cases)
    {
      print_ca_ressources(player, cases[i]);
      if (i + 1 < nb_cases)
	if (dprintf(player->client_fd, ",") < 0)
	  return ;
    }
  if (dprintf(player->client_fd, "}\n") < 0)
    return ;
}

int		_voir(int tabsize, char **tab, t_player *player, t_game *game)
{
  int		case_i;
  t_case	*view;
  int		size;

  (void)tabsize;
  (void)tab;
  if ((size = calculate_view_size(player->level)) == -1)
    return (1);
  if ((view = malloc(sizeof(t_case) * size)) == NULL)
    return (1);
  view[0] = game->map->mp[player->pos.x][player->pos.y];
  case_i = 1;
  while (case_i < size)
    {
      view[case_i] = find_case(case_i, game->map, player);
      case_i++;
    }
  print_cases(player, view, size);
  free(view);
  return (0);
}
