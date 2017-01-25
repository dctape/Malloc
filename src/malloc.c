/*
** malloc.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Jan 24 11:12:34 2017 Ronan Boiteau
** Last update Wed Jan 25 13:48:14 2017 Ronan Boiteau
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

void		my_free(void *ptr)
{
  (void)ptr;
  /* IF ptr is NOT at the end of the mem map */
  /* set chunk->is_available to true */
  /* merge with the prev & next chunks if they are free */
  /* test if the chunk is at the end of the mem map after merge */
  /* ELSE */
  /* remove the chunk from the mem map */
  /* release memory with sbrk() */
}

/*
** Iterates through memory searching for a free
** chunk that can host the new malloc
**
** Warning: Will be moved to another file, should not access heap_start global variable
*/
t_chunk		*find_free_chunk(size_t size, t_chunk *heap_start)
{
  if (heap_start == NULL)
    return (NULL);
  while (heap_start->next != NULL)
    {
      if (heap_start->is_free == true && heap_start->size >= size)
	return (heap_start);
      heap_start = heap_start->next;
    }
  return (NULL);
}

void		*my_malloc(size_t size)
{
  void		*old_brk;
  t_chunk	*chunk; /* Doubly linked list the represents the memory */

  if ((chunk = find_free_chunk(size, heap_start)) != NULL)
    {
      /* USE FREE CHUNK */
      /* resize old chunk to the requested size */
      /* create a new chunk with the remaining mem */
      /* no call to sbrk() */
    }
  else
    {
      /* CREATE NEW CHUNK */
      /* call sbrk() to increase the amount of heap memory by (size + sizeof(t_chunk)) */
      /* create a chunk of requested size */
      /* append it to the end of the memory map */
    }
  old_brk = sbrk(size);
  return (old_brk);
}
