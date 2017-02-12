/*
** my_char_isprintable.c for malloc in /home/ronan/rendu/PSU_2016_malloc
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Feb 12 21:44:16 2017 Ronan Boiteau
** Last update Sun Feb 12 21:44:16 2017 Ronan Boiteau
*/

#include <stdbool.h>
#include "my.h"

int		my_char_isprintable(const char letter)
{
  if (!((letter >= 32 && letter <= 126) || letter == '\0'
	|| (letter >= 7 && letter <= 13)))
    return (false);
  return (true);
}
