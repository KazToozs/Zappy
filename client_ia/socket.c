/*
** socket.c for  in /home/liege_m/rendu/PSU_2015_zappy/client_ia/socket
** 
** Made by maxime liege
** Login   <liege_m@epitech.net>
** 
** Started on  Tue Jun  7 12:07:01 2016 maxime liege
** Last update Wed Jun  8 16:25:32 2016 Matheo MSA
*/

#include <Python.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>

static PyObject		*create_socket(PyObject* self, PyObject* args)
{
  int			sock;
  int			port;
  const char		*ip;
  struct sockaddr_in	s_addr;

  if (!PyArg_ParseTuple(args, "is", &port, &ip))
    return (Py_BuildValue("i", -1));
  s_addr.sin_addr.s_addr = inet_addr(ip);
  s_addr.sin_port = htons(port);
  s_addr.sin_family = AF_INET;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    return (Py_BuildValue("i", -1));
  if (connect(sock, (struct sockaddr *) &s_addr, sizeof(s_addr)) < 0)
    return (Py_BuildValue("i", -1));
  return (Py_BuildValue("i", sock));
}

static PyMethodDef methods_socket[] =
  {
    {"create_socket", (PyCFunction) create_socket,
     METH_VARARGS, "Socket Init"},
    {NULL, NULL, 0, NULL}
  };

static struct PyModuleDef socketmodule = {
  PyModuleDef_HEAD_INIT,
  "initclient",
  NULL,
  -1,
  methods_socket
};

PyMODINIT_FUNC  PyInit_initclient(void)
{
  Py_Initialize();
  return (PyModule_Create(&socketmodule));
}
