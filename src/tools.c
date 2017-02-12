/*
** tools.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Wed Feb  8 09:28:17 2017 Ronan Boiteau
** Last update Sun Feb 12 18:30:58 2017 Ronan Boiteau
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy_malloc.h"

static t_chunk	*free_last_chunk(t_chunk *tmp, t_chunk *ret)
{
  if (tmp->prev != NULL)
    tmp->prev->next = NULL;
  else
    ret = NULL;
  sbrk((tmp->size + tmp->node_size) * -1);
  return (ret);
}

t_chunk		*free_this_chunk(t_chunk *tmp)
{
  t_chunk	*ret;

  ret = tmp;
  tmp->is_free = true;
  while (tmp->prev != NULL && tmp->prev->is_free != false)
    {
      tmp->prev->size += tmp->size + sizeof(t_chunk);
      tmp->prev->next = tmp->next;
      if (tmp->next != NULL)
	tmp->next->prev = tmp->prev;
      tmp = tmp->prev;
    }
  while (tmp->next != NULL && tmp->next->is_free != false)
    {
      tmp->size += tmp->next->size + sizeof(t_chunk);
      tmp->next->next->prev = tmp;
      tmp->next = tmp->next->next;
    }
  if (tmp->next == NULL)
    ret = free_last_chunk(tmp, ret);
  return (ret);
}

t_chunk		*find_free_chunk(size_t const size, t_chunk *tmp)
{
  if (tmp == NULL)
    return (NULL);
  while (tmp->next != NULL)
    {
      if (tmp->is_free == true && size <= tmp->size)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void		*init_memory_map(size_t const size)
{
  t_chunk	*new_memory_map;
  void		*address;

  new_memory_map = sbrk(0);
  if ((address = sbrk(size + sizeof(t_chunk))) == (void *)-1)
    return (NULL);
  new_memory_map->is_free = false;
  new_memory_map->prev = NULL;
  new_memory_map->next = NULL;
  new_memory_map->size = size;
  new_memory_map->node_size = sizeof(t_chunk);
  new_memory_map->address = address + sizeof(t_chunk);
  return (new_memory_map);
}

void		*create_chunk(size_t const size, t_chunk *tmp)
{
  void		*address;

  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = sbrk(0);
  if ((address = sbrk(size + sizeof(t_chunk))) == (void *)-1)
    return (NULL);
  tmp->next->is_free = false;
  tmp->next->prev = tmp;
  tmp->next->next = NULL;
  tmp->next->size = size;
  tmp->next->node_size = sizeof(t_chunk);
  tmp->next->address = address + sizeof(t_chunk);
  return (tmp->next);
}
