/*
** malloc.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Jan 24 11:12:34 2017 Ronan Boiteau
** Last update Mon Jan 30 15:24:57 2017 Ronan Boiteau
*/

#include "libmy_malloc.h"
#include <unistd.h>
#include <stdio.h>

t_chunk		*heap_start = NULL;

void		*my_realloc(void *ptr, size_t size)
{
  (void)ptr;
  (void)size;
  return (NULL);
}

void		show_alloc_mem()
{
  t_chunk	*tmp;

  printf("break : %p\n", sbrk(0));
  tmp = heap_start;
  while (tmp != NULL)
    {
      if (tmp->is_free == false)
	printf("%p - %p : %zu bytes\n", tmp->address,
	       tmp->address + tmp->size, tmp->size); /* that addition though */
      tmp = tmp->next;
    }
}

/*
** Free the mem chunk given as parameter
** Freeing means:
** - Releasing memory with sbrk() if the chunk is at the end of the mem map
** - Setting the chunk's is_free variable to true otherwise
*/
void		free_this_chunk(t_chunk *tmp)
{
  if (tmp->next == NULL)
    {
      if (tmp->prev != NULL)
      	tmp->prev->next = NULL;
      sbrk((tmp->size + sizeof(t_chunk)) * -1);
    }
  else
    {
      tmp->is_free = true;
      while (tmp->prev != NULL && tmp->prev->is_free != false)
	{
	  /* merge with prev */;
	  /* tmp->prev->size += tmp->size; */
	  /* tmp->prev->next = tmp->next; */
	  /* tmp->next->prev = tmp->prev; */
	}
      while (tmp->next != NULL && tmp->next->is_free != false)
	/* merge with next */;
      /* test if the chunk is at the end of the mem map after merge */
    }
  return ;
}

void		my_free(void *ptr)
{
  t_chunk	*tmp;

  printf("%p\n", heap_start->next);
  printf("%p\n", heap_start->next->prev);
  tmp = heap_start;
  while (tmp != NULL)
    {
      /* printf("%p vs. %p\n", tmp->address, ptr); */
      /* if (tmp && tmp->prev) */
      /* 	{ */
      /* 	  /\* tmp->prev = heap_start; /\\* Wtf?! It should already be a pointer to heap_start!!! *\\/ *\/ */
      /* 	  printf("%p\n", tmp->prev->address); */
      /* 	} */
      if (tmp->address == ptr)
	{
	  printf("Found matching chunk!\n");
	  return (free_this_chunk(tmp));
	}
      tmp = tmp->next;
    }
}

/*
** Iterates through memory searching for a free
** chunk that can host the new malloc
**
** Warning: Will be moved to another file, should not access heap_start global variable
*/
t_chunk		*find_free_chunk(size_t const size, t_chunk *tmp)
{
  if (tmp == NULL)
    return (NULL);
  while (tmp->next != NULL)
    {
      if (tmp->is_free == true && tmp->size >= size)
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
  if (sbrk(sizeof(t_chunk)) == (void *)-1)
    return (NULL);
  if ((address = sbrk(size)) == (void *)-1)
    return (NULL);
  new_memory_map->is_free = false;
  new_memory_map->prev = NULL;
  new_memory_map->next = NULL;
  new_memory_map->size = size;
  new_memory_map->address = address;
  return (new_memory_map);
}

/*
** Warning: Will be moved to another file, should not access heap_start global variable
*/
void		*create_chunk(size_t const size, t_chunk *tmp)
{
  void		*address;

  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = sbrk(0);
  if (sbrk(sizeof(t_chunk)) == (void *)-1)
    return (NULL);
  if ((address = sbrk(size)) == (void *)-1)
    return (NULL);
  tmp->next->is_free = false;
  tmp->next->prev = NULL; /* Every variable is correctly stored when calling free() BUT not this one. How is it possible? */
  tmp->next->next = NULL;
  tmp->next->size = size;
  tmp->next->address = address;
  return (tmp->next);
}

void		*my_malloc(size_t size)
{
  t_chunk	*chunk; /* Doubly linked list that represents the memory */

  if (heap_start == NULL)
    {
      if ((heap_start = init_memory_map(size)) == NULL)
	return (NULL);
      return (heap_start->address);
    }
  if ((chunk = find_free_chunk(size, heap_start)) != NULL)
    {
      /* USE FREE CHUNK */
      /* resize old chunk to the requested size */
      /* create a new chunk with the remaining mem */
      /* no call to sbrk() */
    }
  else
    {
      if ((chunk = create_chunk(size, heap_start)) == NULL)
	return (NULL);
      printf("%p\n", heap_start->next);
      printf("%p\n", heap_start->next->prev);
      return (chunk->address);
    }
  return (NULL);
}
