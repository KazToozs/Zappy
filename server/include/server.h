/*
** server.h for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/server/include
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun 21 13:17:49 2016 toozs-_c
** Last update Tue Jun 21 16:02:49 2016 toozs-_c
*/

#ifndef SERV_H_
#define SERV_H_

#include "game.h"
#include "fds.h"

typedef struct          s_ptrs
{
  t_game                *game;
  t_fds                 *fds;
}                       t_ptrs;

extern t_ptrs           g_ptrs;

void		free_cmds(t_cmd *);
void		free_player(t_player *);
void		free_eggs(t_egg *);
void		free_teams(t_team *);
void		free_playercase(t_playercase *);
void		free_map(t_map *);
void		free_game(t_game *);
void		free_ptrs(t_ptrs *);

void		manage_signal();

#endif
