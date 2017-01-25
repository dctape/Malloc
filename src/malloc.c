/*
** malloc.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Jan 24 11:12:34 2017 Ronan Boiteau
** Last update Wed Jan 25 15:57:00 2017 Ronan Boiteau
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
void		get_rid_of_him(t_chunk *tmp)
{
  if (tmp->next == NULL)
    sbrk((tmp->size + sizeof(t_chunk)) * -1);
  else
    {
      tmp->is_free = true;
      if (tmp->prev->is_free == true)
	/* merge with prev */;
      if (tmp->next->is_free == true)
	/* merge with next */;
      /* test if the chunk is at the end of the mem map after merge */
    }
  return ;
}

void		my_free(void *ptr)
{
  t_chunk	*tmp;

  tmp = heap_start;
  while (tmp != NULL)
    {
      if (tmp->address == ptr)
	return (get_rid_of_him(tmp));
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
  t_chunk	*heap_start;

  heap_start = tmp;
  while (tmp->next != NULL)
    tmp = tmp->next;
  /* call sbrk() to increase the amount of heap memory by (size + sizeof(t_chunk)) */
  /* create a chunk of requested size */
  /* append it to the end of the memory map */
  return (heap_start);
}

void		*my_malloc(size_t size)
{
  void		*old_brk;
  t_chunk	*chunk; /* Doubly linked list that represents the memory */

  old_brk = NULL;
  if (heap_start == NULL)
    {
      if ((heap_start = init_memory_map(size)) == NULL)
	return (NULL);
      else
	return (heap_start->address);
    }
  if ((chunk = find_free_chunk(size, heap_start)) != NULL)
    {
      /* USE FREE CHUNK */
      /* resize old chunk to the requested size */
      /* create a new chunk with the remaining mem */
      /* no call to sbrk() */
    }
  else if ((heap_start = create_chunk(size, heap_start)) == NULL)
    return (NULL);
  return (old_brk);
}
