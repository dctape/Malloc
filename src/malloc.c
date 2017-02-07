/*
** malloc.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Jan 24 11:12:34 2017 Ronan Boiteau
** Last update Tue Feb  7 18:33:23 2017 Ronan Boiteau
*/

#include "libmy_malloc.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

t_chunk		*find_chunk(t_chunk *tmp, void *ptr)
{
  while (tmp != NULL)
    {
      if (tmp->address == ptr)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void		*calloc(size_t nmemb, size_t size)
{
  void		*ptr;

  ptr = malloc(size * nmemb);
  memset(ptr, 0, size * nmemb);
  return (ptr);
}

/* void		my_memcpy(void *dest, void *src, size_t n) */
/* { */
/*   size_t	*csrc = (size_t *)src; */
/*   size_t	*cdest = (size_t *)dest; */

/*   for (int i=0; i<n; i++) */
/*     cdest[i] = csrc[i]; */
/* } */

void		*realloc(void *ptr, size_t size)
{
  void		*new_ptr;
  t_chunk	*old;
  t_chunk	*new;

  /* RTFM */
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
  /* memcpy(new->address, old->address, old->size); */
  free(ptr);
  return (new_ptr);
}

/* void		show_alloc_mem() */
/* { */
/*   t_chunk	*tmp; */

/*   printf("break : %p\n", sbrk(0)); */
/*   tmp = g_heap_start; */
/*   while (tmp != NULL) */
/*     { */
/*       if (tmp->is_free == false) */
/* 	printf("%p - %p : %zu bytes\n", tmp->address, */
/* 	       tmp->address + tmp->size, tmp->size); /\* that addition though *\/ */
/*       else */
/* 	{ */
/* 	  printf("FREE CHUNK\n"); */
/* 	  printf("%p\n", tmp); */
/* 	} */
/*       tmp = tmp->next; */
/*     } */
/* } */

/*
** Free the mem chunk given as parameter
** Freeing means:
** - Releasing memory with sbrk() if the chunk is at the end of the mem map
** - Setting the chunk's is_free variable to true otherwise
*/
void		free_this_chunk(t_chunk *tmp)
{
  tmp->is_free = true;
  while (tmp->prev != NULL && tmp->prev->is_free != false)
    {
      /* printf("MERGING WITH PREV\n"); */
      tmp->prev->size += tmp->size;
      tmp->prev->node_size += sizeof(t_chunk);
      tmp->prev->next = tmp->next;
      if (tmp->next != NULL)
	tmp->next->prev = tmp->prev;
      tmp = tmp->prev;
    }
  while (tmp->next != NULL && tmp->next->is_free != false)
    {
      /* printf("MERGING WITH NEXT\n"); */
      tmp->size += tmp->next->size;
      tmp->node_size += sizeof(t_chunk);
      tmp->next = tmp->next->next;
    }
  if (tmp->next == NULL)
    {
      if (tmp->prev != NULL)
	tmp->prev->next = NULL;
      else
      	g_heap_start = NULL;
      sbrk((tmp->size + tmp->node_size) * -1);
    }
}

void		free(void *ptr)
{
  t_chunk	*tmp;

  if (ptr == NULL)
    return ;
  tmp = g_heap_start;
  while (tmp != NULL)
    {
      /* printf("%p vs. %p\n", tmp->address, ptr); */
      if (tmp->address == ptr)
	{
	  /* printf("Found matching chunk!\n"); */
	  return (free_this_chunk(tmp));
	}
      tmp = tmp->next;
    }
}

/*
** Iterates through memory searching for a free
** chunk that can host the new malloc
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

void		*malloc(size_t size)
{
  t_chunk	*chunk; /* Doubly linked list representing the memory */

  if (g_heap_start == NULL)
    {
      if ((g_heap_start = init_memory_map(size)) == NULL)
	return (NULL);
      return (g_heap_start->address);
    }
  /* if ((chunk = find_free_chunk(size, g_heap_start)) != NULL) */
  /*   { */
  /*     /\* USE FREE CHUNK *\/ */
  /*     /\* resize old chunk to the requested size *\/ */
  /*     /\* create a new chunk with the remaining mem *\/ */
  /*     /\* no call to sbrk()! *\/ */
  /*   } */
  /* else */
  /*   { */
  if ((chunk = create_chunk(size, g_heap_start)) == NULL)
    return (NULL);
  return (chunk->address);
  /* } */
  return (NULL);
}
