/*
** my_putstr.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 12 21:45:19 2017 Ronan Boiteau
** Last update Sun Feb 12 21:45:20 2017 Ronan Boiteau
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

t_uint		my_putstr_fd(int fd, const char *str)
{
  if (str == NULL)
    {
      write(fd, "(null)", my_strlen("(null)"));
      return (my_strlen("(null)"));
    }
  write(fd, str, my_strlen(str));
  return (my_strlen(str));
}

t_uint		my_putstr(const char *str)
{
  return (my_putstr_fd(STDOUT, str));
}
