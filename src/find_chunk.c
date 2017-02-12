/*
** find_chunk.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 12 18:25:23 2017 Ronan Boiteau
** Last update Sun Feb 12 18:25:25 2017 Ronan Boiteau
*/

#include <stdlib.h>
#include "libmy_malloc.h"

t_chunk		*find_chunk(t_chunk *tmp, void *ptr)
{
  if (ptr == NULL)
    return (NULL);
  while (tmp != NULL)
    {
      if (tmp->address == ptr)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
