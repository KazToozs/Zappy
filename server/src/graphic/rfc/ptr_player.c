/*
** ptr_player.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src/rfc
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Jun  8 15:26:54 2016 pallua_j
** Last update Mon Jun 13 17:33:13 2016 pallua_j
*/

#include "game.h"
#include "my.h"

t_player	*get_player(t_game *this, int nb)
{
  t_team	*ttmp;
  t_player	*tmp;

  ttmp = this->teams;
  while (ttmp)
    {
      tmp = ttmp->players;
      while (tmp)
	{
	  if (tmp->nb == nb)
	    return (tmp);
	  tmp = tmp->next;
	}
      ttmp = ttmp->next;
    }
  return (NULL);
}

bool		_ppo_ptr(t_game *this, char **tab, int fd)
{
  int		nb;
  t_player	*tmp;

  if (tab[1] != NULL)
    {
      if ((nb = atoi(tab[1])) == 0)
	if (my_strcmp("0", tab[1]) != 0)
	  return (false);
      if ((tmp = get_player(this, nb)) == NULL)
	return (false);
      player_position_graph(tmp, fd);
      return (true);
    }
  return (false);
}

bool		_plv_ptr(t_game *this, char **tab, int fd)
{
  int		nb;
  t_player	*tmp;

  if (tab[1] != NULL)
    {
      if ((nb = atoi(tab[1])) == 0)
	if (my_strcmp("0", tab[1]) != 0)
	  return (false);
      if ((tmp = get_player(this, nb)) == NULL)
	return (false);
      player_level_graph(tmp, fd);
      return (true);
    }
  return (false);
}

bool		_pin_ptr(t_game *this, char **tab, int fd)
{
  int		nb;
  t_player	*tmp;

  if (tab[1] != NULL)
    {
      if ((nb = atoi(tab[1])) == 0)
	if (my_strcmp("0", tab[1]) != 0)
	  return (false);
      if ((tmp = get_player(this, nb)) == NULL)
	return (false);
      player_inventaire_graph(tmp, fd);
      return (true);
    }
  return (false);
}
