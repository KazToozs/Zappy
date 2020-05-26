/*
** network.h for  in /home/liegem/rendu/PSU_2015_zappy/zappy_network/includes
** 
** Made by liegem
** Login   <liegem@epitech.net>
** 
** Started on  Tue Jun 14 11:23:07 2016 liegem
** Last update Wed Jun 22 18:14:02 2016 liegem
*/

#ifndef NETWORK_H
# define NETWORK_H

#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

# define GRAPH "GRAPHIC"

#include "game.h"
#include "parameters.h"
#include "player.h"
#include "fds.h"

int	set_fd_players(t_team *team, fd_set *rdfs, int max);
bool	is_ghost_mode(t_player **player, int fd, t_game *game);
bool	is_full_team(t_player *player, int ccount);
int	set_fd_graph(t_fds *graph, fd_set *rdfs, int max);
void	read_socket(char **buff, int sock);

bool	is_exist_team(char *, t_fds **, t_fds *, t_game *);
bool	is_cmd_full(t_cmd *cmd);
bool	is_disconnect(char *, t_fds **, t_fds **);
bool	is_graph_disconnect(char *, t_fds **, t_fds **);
bool	is_player_disconnect(char *, t_player **, t_player **);

void	manage_clients(char *str, t_fds **, t_fds *, t_game *);
int	accept_client(int sock);

void	check_player(fd_set *rdfs, t_game *);
void	check_graph(fd_set *rdfs, t_game *);
void	check_client(t_fds **fds, fd_set *rdfs, t_game *);

bool	select_sock(int , fd_set *, t_fds **, t_game *);
void	data_network(t_data *data);
void	init_network(t_data *data);

#endif /* !NETWORK_H */
