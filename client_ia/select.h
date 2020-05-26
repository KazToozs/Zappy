/*
** select.h for  in /home/liege_m/rendu/PSU_2015_zappy/client_ia
** 
** Made by maxime liege
** Login   <liege_m@epitech.net>
** 
** Started on  Thu Jun  9 14:25:55 2016 maxime liege
** Last update Thu Jun 16 13:55:08 2016 liegem
*/

#ifndef SELECT_H_
# define SELECT_H_

#include <Python.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

int		read_sock(int, char **);
static PyObject	*write_sock(PyObject *, PyObject *);
static PyObject	*select_sock(PyObject *, PyObject *);
PyMODINIT_FUNC	PyInit_selectclient(void);

#endif /* !SELECT_H */
