#include <unistd.h>
#include <stdio.h>
#include "libmy_malloc.h"

int		main(void)
{
  int		*lel;
  int		*lelel;
  char		*str;

  printf("Before malloc\t\t%p\n", sbrk(0));
  lel = my_malloc(sizeof(int) * 2);
  printf("After first malloc\t%p\n", sbrk(0));
  lelel = my_malloc(sizeof(int));
  printf("After second malloc\t%p\n", sbrk(0));
  lel[0] = 102;
  lel[1] = 3102;
  str = my_malloc(sizeof(char) * 4);
  printf("After third malloc\t%p\n", sbrk(0));
  str[0] = 'a';
  str[1] = 'b';
  str[2] = 'c';
  str[3] = '\0';
  *lelel = 42;
  printf("Before first free\t%p\n", sbrk(0));
  my_free(lel);
  printf("After first free\t%p\n", sbrk(0));
  my_free(lelel);
  printf("After second free\t%p\n", sbrk(0));
  my_free(str);
  /* show_alloc_mem(); */
  printf("After third free\t%p\n", sbrk(0));
  return (0);
}
