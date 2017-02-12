/*
** my_putchar.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 12 21:48:42 2017 Ronan Boiteau
** Last update Sun Feb 12 21:48:45 2017 Ronan Boiteau
*/

#include <unistd.h>
#include "my.h"

t_uint		my_putchar_fd(int fd, const char letter)
{
  write(fd, &letter, 1);
  return (1);
}

t_uint		my_putchar(const char letter)
{
  my_putchar_fd(1, letter);
  return (1);
}
