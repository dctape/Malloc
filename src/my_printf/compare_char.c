/*
** compare_char.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 12 21:45:13 2017 Ronan Boiteau
** Last update Sun Feb 12 21:45:13 2017 Ronan Boiteau
*/

#include <stdbool.h>
#include "my.h"
#include "printf_flags.h"

int		char_isflag(const char letter, const t_flag *flags)
{
  int		idx;

  idx = 0;
  while (idx < FLAGS_NBR)
    {
      if (letter == flags[idx].flag_char)
	return (idx);
      idx += 1;
    }
  return (-1);
}

int		char_isletter(const char letter)
{
  if ((letter >= 'a' && letter <= 'z') ||
      (letter >= 'A' && letter <= 'Z') ||
      letter == '/' || letter == '{' ||
      letter == '\n' || letter == '%' ||
      letter == '}' || letter == '=' ||
      letter == ':' || letter == ',' ||
      letter == ';' || letter == '[' ||
      letter == ']' || letter == '(' ||
      letter == ')' || letter == 'l')
    return (true);
  return (false);
}
