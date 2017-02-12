#include <unistd.h>
#include <stdio.h>
#include "libmy_malloc.h"

int		main(void)
{
  int		*lel;
  int		*lelel;
  char		*str;
  int		*mdr;

  printf("Before malloc\t\t%p\n", sbrk(0));
  lel = malloc(sizeof(int) * 2);
  printf("After first malloc\t%p\n", sbrk(0));
  lelel = malloc(sizeof(int));
  printf("After second malloc\t%p\n", sbrk(0));
  lel[0] = 102;
  lel[1] = 3102;
  str = malloc(sizeof(char) * 4);
  printf("After third malloc\t%p\n", sbrk(0));
  str[0] = 'a';
  str[1] = 'b';
  str[2] = 'c';
  str[3] = '\0';
  *lelel = 42;
  printf("Before first free\t%p\n", sbrk(0));
  free(lelel);
  printf("After first free\t%p\n", sbrk(0));
  free(lel);
  printf("After second free\t%p\n", sbrk(0));
  show_alloc_mem();
  mdr = malloc(sizeof(int));
  *mdr = 1;
  printf("Before malloc\t\t%p\n", sbrk(0));
  lel = calloc(sizeof(int), 2);
  printf("After first calloc\t%p\n", sbrk(0));
  lel[1] = 3042;
  printf("%i - %i\n", lel[0], lel[1]);
  lel = realloc(lel, sizeof(int) * 4);
  printf("After first realloc\t%p\n", sbrk(0));
  lel[2] = 4232;
  lel[3] = 42;
  printf("%i - %i - %i - %i\n", lel[0], lel[1], lel[2], lel[3]);
  printf("Before first free\t%p\n", sbrk(0));
  free(lel);
  printf("After first free\t%p\n", sbrk(0));
  free(mdr);
  free(str);
  printf("After third free\t%p\n", sbrk(0));
  return (0);
}
