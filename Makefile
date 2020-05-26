##
## Makefile for  in /home/liegem/rendu/PSU_2015_zappy
##
## Made by liegem
## Login   <liegem@epitech.net>
##
## Started on  Wed Jun 15 12:33:53 2016 liegem
## Last update Fri Jun 24 14:51:28 2016 toozs-_c
##

SRC=		server/src/main/main.c				\
		server/src/main/free_ptrs.c			\
		server/src/main/signal.c			\
		server/src/main/free_teams.c			\
		server/src/main/my.c				\
		server/src/main/my_str_tab.c			\
		server/src/args/check_args.c			\
		server/src/args/param_checks/c_param.c		\
		server/src/args/param_checks/n_param.c		\
		server/src/args/param_checks/p_param.c		\
		server/src/args/param_checks/t_param.c		\
		server/src/args/param_checks/x_param.c		\
		server/src/args/param_checks/y_param.c		\
		server/src/lists/team.c				\
		server/src/lists/fds.c				\
		server/src/lists/egg.c				\
		server/src/lists/player.c			\
		server/src/lists/playercase.c			\
		server/src/lists/cmd_queue.c			\
		server/src/network/init_network.c		\
		server/src/network/network.c			\
		server/src/network/net_loop.c			\
		server/src/network/set_fd.c			\
		server/src/network/manage.c			\
		server/src/network/ccount.c			\
		server/src/game/game.c				\
		server/src/game/map.c				\
		server/src/game/game_checks.c			\
		server/src/game/end_game.c			\
		server/src/graphic/start.c			\
		server/src/graphic/rfc/ptr_map.c		\
		server/src/graphic/rfc/ptr_player.c		\
		server/src/graphic/rfc/ptr_time.c		\
		server/src/graphic/rfc/rfc_actions.c		\
		server/src/graphic/rfc/rfc_egg.c		\
		server/src/graphic/rfc/rfc_incantation.c	\
		server/src/graphic/rfc/rfc_map.c		\
		server/src/graphic/rfc/rfc_map_func.c		\
		server/src/graphic/rfc/rfc_message.c		\
		server/src/graphic/rfc/rfc_player.c		\
		server/src/graphic/rfc/rfc_player_func.c	\
		server/src/graphic/rfc/rfc_res.c		\
		server/src/graphic/rfc/rfc_time.c		\
		server/src/actions/actions.c 			\
		server/src/actions/do_action.c			\
		server/src/actions/timers.c			\
		server/src/actions/actions/a_avance.c		\
		server/src/actions/actions/a_broadcast.c	\
		server/src/actions/actions/a_connect.c		\
		server/src/actions/actions/a_droite.c		\
		server/src/actions/actions/a_expulse.c		\
		server/src/actions/actions/a_fork.c		\
		server/src/actions/actions/a_gauche.c		\
		server/src/actions/actions/a_incantation.c	\
		server/src/actions/actions/a_inventaire.c	\
		server/src/actions/actions/a_pose.c		\
		server/src/actions/actions/a_prend.c		\
		server/src/actions/actions/a_voir.c		\
		server/src/actions/actions/find_team.c		\
		server/src/actions/actions/levelup.c		\
		server/src/actions/actions/move.c		\
		server/src/actions/actions/ressources.c		\
		server/src/actions/actions/view.c		\

OBJ=		$(SRC:.c=.o)

CC=		gcc

CFLAGS=		-W -Wall -Wextra -I./server/include

NAME=		zappy_server

AI=		zappy_ai

all:		$(NAME) $(AI)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

$(AI):		
		cp ./client_ia/client_ia.py ./$(AI)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME) $(AI)

re:		fclean all
