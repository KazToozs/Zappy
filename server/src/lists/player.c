/*
** playercase.c for zappy in /home/pallua_j/rendu/tmp/zappy/src
**
** Made by pallua_j
** Login   <pallua_j@epitech.net>
**
** Started on  Tue Jun  7 13:45:57 2016 pallua_j
** Last update Fri Jun 24 13:41:37 2016 toozs-_c
*/

#include <stdlib.h>
#include <unistd.h>
#include "game.h"
#include "my.h"
#include "server.h"
#include "player.h"

t_player	*remp_player(t_player *player, int fd,
			     t_game *game, char *team)
{
  static int	nb = 1;

  player->client_fd = fd;
  player->queue = NULL;
  player->action = NOTHING;
  player->level = 1;
  player->team_name = my_strdup(team);
  player->inventaire[0] = 10;
  player->inventaire[1] = 0;
  player->inventaire[2] = 0;
  player->inventaire[3] = 0;
  player->inventaire[4] = 0;
  player->inventaire[5] = 0;
  player->inventaire[6] = 0;
  player->life = 1260;
  my_clock_gettime(&player->start);
  player->pos.x = rand() % game->map->size_x;
  player->pos.y = rand() % game->map->size_y;
  player->nb = nb++;
  player->next = NULL;
  player->orientation = NORD;
  add_food(game);
  _mct(game);
  return (player);
}

void		set_player_list(t_player **list, t_player *block)
{
  t_player 	*tmp;

  if ((*list) == NULL)
    {
      block->prev = NULL;
      (*list) = block;
    }
  else
    {
      tmp = (*list);
      while ((*list)->next != NULL)
        (*list) = (*list)->next;
      (*list)->next = block;
      (*list)->next->prev = (*list);
      (*list) = tmp;
    }
}

int		player_push_back_ghost(t_player **list, int fd,
				 t_game *game, char *team)
{
  t_player 	*block;

  if ((block = malloc(sizeof(*block))) == NULL)
    return (1);
  block->ghost = 1;
  block = remp_player(block, fd, game, team);
  set_player_list(list, block);
  return (0);
}

int		player_push_back(t_player **list, int fd,
				 t_game *game, char *team)
{
  t_player 	*block;

  if ((block = malloc(sizeof(*block))) == NULL)
    return (1);
  block = remp_player(block, fd, game, team);
  _pnw(game, block);
  _pin(game, block);
  case_push_back(&game->map->mp[block->pos.x][block->pos.y].players, block);
  block->ghost = 0;
  set_player_list(list, block);
  if (dprintf(fd, "%d\n%d %d\n",
	      game->ccount - get_ccount(game, team),
	      game->map->size_x, game->map->size_y) < 0)
    return (-1);
  return (0);
}

void		player_remove_node(t_player **head, t_player **node)
{
  t_player	*tmp;

  tmp = (*node);
  if ((*node)->prev != NULL)
    (*node)->prev->next = (*node)->next;
  if ((*node)->next != NULL)
    (*node)->next->prev = (*node)->prev;
  if ((*node)->prev == NULL)
    (*head) = (*head)->next;
  (*node) = (*head);
  if (tmp->team_name)
    free(tmp->team_name);
  free_cmds(tmp->queue);
  if (tmp->ghost == 0)
    if (close(tmp->client_fd) == -1)
      exit(1);
  free(tmp);
}
