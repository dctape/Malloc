/*
** my_memcpy.c for my_memcpy in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Wed Feb  8 10:04:48 2017 Ronan Boiteau
** Last update Wed Feb  8 10:05:39 2017 Ronan Boiteau
*/

#include "libmy_malloc.h"

void		my_memcpy(t_chunk *dest, t_chunk *src)
{
  size_t	*ptr_src;
  size_t	*ptr_dest;
  int		idx;

  ptr_src = (size_t *)src->address;
  ptr_dest = (size_t *)dest->address;
  idx = 0;
  while (idx * sizeof(size_t) < src->size && idx * sizeof(size_t) < dest->size)
    {
      ptr_dest[idx] = ptr_src[idx];
      ++idx;
    }
}
