/*
** select.c for  in /home/liege_m/rendu/PSU_2015_zappy/client_ia
**
** Made by maxime liege
** Login   <liege_m@epitech.net>
**
** Started on  Tue Jun  7 17:15:58 2016 maxime liege
** Last update Fri Jun 24 10:31:13 2016 toozs-_c
*/

#include "select.h"

static PyMethodDef methods_socket[] =
  {
    {"select_sock", (PyCFunction) select_sock,
    METH_VARARGS, "Check if something to read/write"},
    {"write_sock", (PyCFunction) write_sock,
    METH_VARARGS, "write in the socket"},
    {NULL, NULL, 0, NULL}
  };

static struct PyModuleDef selectmodule = {
  PyModuleDef_HEAD_INIT,
  "selectclient",
  NULL,
  -1,
  methods_socket
};

int	read_sock(int sock, char **buff)
{
  char	line[4096];
  short	pass;

  pass = 0;
  bzero(line, 4096);
  while (strchr(line, '\n') == NULL)
    {
      bzero(line, 4096);
      if (read(sock, line, 4096) == 0)
	return (-1);
      if (pass >= 1
	  && (int) (strlen((*buff)) + strlen(line)) > (4096 * pass))
	{
	  if (((*buff) = realloc((*buff), 4096)) == NULL)
	    exit(EXIT_FAILURE);
	  pass++;
	}
      else
	pass = 1;
      strcat((*buff), line);
    }
  return (0);
}

static PyObject		*write_sock(PyObject* self, PyObject* args)
{
  const char		*str;
  int			sock;
  int			len;

  str = NULL;
  if (!PyArg_ParseTuple(args, "is", &sock, &str))
    return (Py_BuildValue("i", -1));
  if ((len = strlen(str)) == -1)
    return (Py_BuildValue("i", -1));
  if ((write(sock, str, len)) == -1)
    return (Py_BuildValue("i", -1));
  return (Py_BuildValue("i", len));
}

static PyObject		*select_sock(PyObject* self, PyObject* args)
{
  char			*str;
  int			sock;
  struct timeval	tv;
  fd_set		rdfs;

  tv.tv_sec = 0;
  tv.tv_usec = 25;
  FD_ZERO(&rdfs);
  if (!PyArg_ParseTuple(args, "i", &sock))
    return (Py_BuildValue("i", -1));
  FD_SET(sock, &rdfs);
  if (select(sock + 1, &rdfs, NULL, NULL, &tv) <= 0)
    return (Py_BuildValue("i", 0));
  if ((str = calloc(sizeof(char), sizeof(char) * 4096)) == NULL)
    return (Py_BuildValue("i", -1));
  if (FD_ISSET(sock, &rdfs))
    if ((read_sock(sock, &str)) == -1)
      exit(EXIT_FAILURE);
  if (str == NULL)
    {
      free(str);
      return (Py_BuildValue("i", -1));
    }
  return (Py_BuildValue("s", str));
}

PyMODINIT_FUNC  PyInit_selectclient(void)
{
  Py_Initialize();
  return (PyModule_Create(&selectmodule));
}
