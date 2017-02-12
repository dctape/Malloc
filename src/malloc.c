/*
** malloc.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Jan 24 11:12:34 2017 Ronan Boiteau
** Last update Sun Feb 12 18:00:23 2017 Ronan Boiteau
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "libmy_malloc.h"
#include "my.h"

t_chunk		*g_heap_start = NULL;

void		show_alloc_mem()
{
  t_chunk	*tmp;

  my_printf("break : %p\n", sbrk(0));
  tmp = g_heap_start;
  while (tmp != NULL)
    {
      if (tmp->is_free == false)
	my_printf("%p - %p : %u bytes\n", tmp->address,
	       tmp->address + tmp->size, tmp->size);
      tmp = tmp->next;
    }
}

void		*calloc(size_t nmemb, size_t size)
{
  void		*ptr;

  ptr = malloc(size * nmemb);
  if (ptr == NULL)
    return (NULL);
  memset(ptr, 0, size * nmemb);
  return (ptr);
}

void		*realloc(void *ptr, size_t size)
{
  void		*new_ptr;
  t_chunk	*old;
  t_chunk	*new;

  /* RTFM */
  /* check if new->size < old->size */
  /* check if we can merge with neighboors instead of re-malloc-ing a chunk */
  /* if (old->next != NULL && old->next->is_free == true) */
  /*   return ; */
  /* else if (old->prev != NULL && old->prev->is_free == true) */
  /*   return ; */
  new_ptr = malloc(size);
  if (new_ptr == NULL)
    return (NULL);
  old = find_chunk(g_heap_start, ptr);
  new = find_chunk(g_heap_start, new_ptr);
  if (old == NULL || new == NULL)
    return (new_ptr);
  my_memcpy(new, old);
  free(ptr);
  return (new_ptr);
}

void		free(void *ptr)
{
  t_chunk	*tmp;

  if (ptr == NULL)
    return ;
  tmp = g_heap_start;
  while (tmp != NULL)
    {
      if (tmp->address == ptr)
	{
	  if (free_this_chunk(tmp) == NULL)
	    g_heap_start = NULL;
	  return ;
	}
      tmp = tmp->next;
    }
}

void		*malloc(size_t size)
{
  t_chunk	*chunk;

  if (g_heap_start == NULL)
    {
      if ((g_heap_start = init_memory_map(size)) == NULL)
	return (NULL);
      return (g_heap_start->address);
    }
  if ((chunk = find_free_chunk(size, g_heap_start)) != NULL)
    {
      /* use_free_chunk(chunk, size); */
      chunk->is_free = false;
      return (chunk->address);
    }
  else
    {
      if ((chunk = create_chunk(size, g_heap_start)) == NULL)
	return (NULL);
      return (chunk->address);
    }
  return (NULL);
}
