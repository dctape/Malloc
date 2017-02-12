/*
** my_showstr.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 12 21:44:50 2017 Ronan Boiteau
** Last update Sun Feb 12 21:44:51 2017 Ronan Boiteau
*/

#include <stdlib.h>
#include "my.h"
#include "printf_puts.h"

int		my_showstr(int fd, const char *str)
{
  t_uint	idx;

  idx = 0;
  if (str == NULL)
    {
      my_putstr_fd(fd, "(null)");
      return (my_strlen("(null)"));
    }
  while (str[idx] != '\0')
    {
      if (my_char_isprintable(str[idx]))
	my_putchar_fd(fd, str[idx]);
      else
	{
	  my_putchar_fd(fd, '\\');
	  if (str[idx] < 16)
	    my_putchar_fd(fd, '0');
	  my_putnbr_base_fd(fd, str[idx], "0123456789abcdef");
	}
      idx += 1;
    }
  return (0);
}
