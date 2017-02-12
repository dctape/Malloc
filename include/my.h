/*
** my.h for libmy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Oct  8 10:33:26 2015 Ronan Boiteau
** Last update Sun Feb 12 17:21:16 2017 Ronan Boiteau
*/

#ifndef MY_H_
# define MY_H_

# include "my_macro.h"
# include "my_typedef.h"

int	my_char_isprintable(const char letter);
int	my_dprintf(int fd, const char *format, ...);
int	my_printf(const char *format, ...);
int	my_strlen(const char *str);

#endif /* !MY_H_ */
