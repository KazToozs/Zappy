/*
** rfc_map.c for zappy in /home/pallua_j/rendu/tmp/PSU_2015_zappy/zappy_jules/src
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Jun  8 10:20:10 2016 pallua_j
** Last update Tue Jun 14 13:03:57 2016 pallua_j
*/

#include "game.h"

void		size_map_graph(t_game *this, int fd)
{
  if (dprintf(fd, "msz %d %d\n", this->map->size_x, this->map->size_y) < 0)
    return ;
}

void		print_case_graph(t_game *this, int x, int y, int fd)
{
   if (x >= this->map->size_x || y >= this->map->size_y)
     {
       if (dprintf(fd, "sbp\n") < 0)
	 return ;
     }
   else
     if (dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n",
		 x, y, this->map->mp[x][y].ressources[0],
		 this->map->mp[x][y].ressources[1],
		 this->map->mp[x][y].ressources[2],
		 this->map->mp[x][y].ressources[3],
		 this->map->mp[x][y].ressources[4],
		 this->map->mp[x][y].ressources[5],
		 this->map->mp[x][y].ressources[6]) < 0)
       return ;
}

void		print_team_graph(t_game *this, int fd)
{
  t_team	*tmp;

  tmp = this->teams;
  while (tmp)
    {
      if (dprintf(fd, "tna %s\n", tmp->name) < 0)
	return ;
      tmp = tmp->next;
    }
}

void		print_map_graph(t_game *this, int fd)
{
  int		x;
  int		y;

  x = 0;
  while (x < this->map->size_x)
    {
      y = 0;
      while (y < this->map->size_y)
	{
	  print_case_graph(this, x, y, fd);
	  y++;
	}
      x++;
    }
}
