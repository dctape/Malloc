/*
** my_strlen.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 12 21:44:32 2017 Ronan Boiteau
** Last update Sun Feb 12 21:44:32 2017 Ronan Boiteau
*/

#include <stdlib.h>

int		my_strlen(const char *str)
{
  int		idx;

  idx = 0;
  while (str != NULL && str[idx])
    idx += 1;
  return (idx);
}
