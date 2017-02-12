/*
** my_macro.h for libmy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct 27 14:04:25 2015 Ronan Boiteau
** Last update Sun Feb 12 17:21:26 2017 Ronan Boiteau
*/

#ifndef MY_MACRO_H_
# define MY_MACRO_H_

# define ABS(nbr)		(nbr < 0 ? -nbr : nbr)
# define MAX(nbr_1, nbr_2)	(nbr_1 < nbr_2 ? nbr_2 : nbr_1)
# define MIN(nbr_1, nbr_2)	(nbr_1 > nbr_2 ? nbr_2 : nbr_1)

# define STDIN	(0)
# define STDOUT	(1)
# define STDERR	(2)

#endif /* !MY_MACRO_H_ */
