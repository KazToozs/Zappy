/*
** rfc_actions.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Jun  8 14:04:17 2016 pallua_j
** Last update Tue Jun 21 16:51:18 2016 toozs-_c
*/

#include "game.h"
#include "my.h"

t_graphact	g_graph_action[] =
  {
    {"msz", &_msz_ptr},
    {"bct", &_bct_ptr},
    {"mct", &_mct_ptr},
    {"tna", &_tna_ptr},
    {"ppo", &_ppo_ptr},
    {"plv", &_plv_ptr},
    {"pin", &_pin_ptr},
    {"sgt", &_sgt_ptr},
    {"sst", &_sst_ptr},
    {NULL, NULL}
  };

void		do_graph_action(t_game *this, char *line, int fd)
{
  int		cpt;
  char		**tab;
  bool		ok;

  cpt = 0;
  tab = my_str_tab(line);
  ok = false;
  while (g_graph_action[cpt].act)
    {
      if (my_strcmp(tab[0], g_graph_action[cpt].act) == 0)
	{
	  ok = true;
	  if (g_graph_action[cpt].ptr(this, tab, fd) == false)
	    if (dprintf(fd, "sbp\n") < 0)
	      {
		free_tab(tab);
		return ;
	      }
	}
      cpt++;
    }
  free_tab(tab);
  if (ok == false)
    if (dprintf(fd, "suc\n") < 0)
      return ;
}
