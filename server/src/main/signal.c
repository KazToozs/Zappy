/*
** signal.c for zappy in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_zappy/server/src
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Jun 21 15:56:39 2016 toozs-_c
** Last update Tue Jun 21 16:23:47 2016 toozs-_c
*/

#include <signal.h>
#include "server.h"

void            handler(int sig)
{
  if (sig == SIGINT)
    {
      free_ptrs(&g_ptrs);
      exit(130);
    }
}

void		manage_signal()
{
  if (signal(SIGINT, &handler) == SIG_ERR)
    {
      exit(1);
    }
}
