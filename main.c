#include <unistd.h>
#include <stdio.h>
#include "libmy_malloc.h"

int		main(void)
{
  int		*lel;
  int		*lelel;

  printf("Before malloc\t\t%p\n", sbrk(0));
  lel = my_malloc(sizeof(int));
  printf("After first malloc\t%p\n", sbrk(0));
  lelel = my_malloc(sizeof(int) * 2);
  printf("After second malloc\t%p\n", sbrk(0));
  lel[0] = 102;
  lel[1] = 3102;
  /* show_alloc_mem(); */
  my_free(lelel);
  printf("After first free\t%p\n", sbrk(0));
  my_free(lel);
  printf("After second free\t%p\n", sbrk(0));
  return (0);
}
