/*
** libmy_malloc.h for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Jan 24 10:45:45 2017 Ronan Boiteau
** Last update Wed Feb  1 11:30:02 2017 Ronan Boiteau
*/

#ifndef LIBMY_MALLOC_H_
# define LIBMY_MALLOC_H_

# include <stdlib.h>
# include <stdbool.h>

void		free(void *ptr);
void		*malloc(size_t size);
/* void		*calloc(size_t nmemb, size_t size); -> à faire en bonus ? */
void		*realloc(void *ptr, size_t size);
void		show_alloc_mem();

typedef struct	s_chunk t_chunk;

struct		s_chunk
{
  t_chunk	*prev;
  t_chunk	*next;
  bool		is_free;
  size_t	size;
  size_t	node_size;
  void		*address;
};

#endif /* LIBMY_MALLOC_H_ */
