/*
** map.h for zapy in /home/pallua_j/rendu/tmp/zappy/include
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Jun  6 21:48:18 2016 pallua_j
** Last update Wed Jun 22 11:30:54 2016 toozs-_c
*/

#ifndef _ZAPPY__H_
# define _ZAPPY__H_

#include <stdlib.h>
#include <time.h>
#include "player.h"

/*
** Structure de la map
*/

typedef enum		e_resname
  {
    NOURRITURE,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NONE
  }			e_resname;

#define NBREF		6

typedef struct		s_playercase
{
  struct s_playercase	*prev;
  t_player		*player;
  struct s_playercase	*next;
}			t_playercase;

typedef struct		s_case
{
  t_pos			pos;
  int			ressources[NBREF + 1];
  t_playercase		*players;
}			t_case;

typedef struct		s_map
{
  int			size_x;
  int			size_y;
  t_case		**mp;
}			t_map;

void            remove_pl_from_case(t_player *player, t_case *ca);

/*
** Prototype des listes chaînées
*/

int			case_push_back(t_playercase **, t_player *);
void			case_remove_node(t_playercase **, t_playercase **);

/*
** Prototype génération de map
*/

t_map			*generate_map(int , int);

#endif /*!_ZAPPY__H_*/
