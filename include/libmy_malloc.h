/*
** libmy_malloc.h for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Tue Jan 24 10:45:45 2017 Ronan Boiteau
** Last update Wed Jan 25 13:36:52 2017 Ronan Boiteau
*/

#ifndef LIBMY_MALLOC_H_
# define LIBMY_MALLOC_H_

# include <stdlib.h>
# include <stdbool.h>

void		my_free(void *ptr);
void		*my_malloc(size_t size);
/* void		*my_calloc(size_t size); -> très simple quand on a malloc() - à faire en bonus ?*/
void		*my_realloc(void *ptr, size_t size);
void		show_alloc_mem();

typedef struct	s_chunk t_chunk;

struct		s_chunk
{
  t_chunk	*prev;
  bool		is_free;
  void		*address;
  size_t	size;
  t_chunk	*next;
};

#endif /* LIBMY_MALLOC_H_ */
