/* m002.c - Sort three variables.

   This program takes three integers read as command 
   line arguments and outputs them in ascending order.

   E.g.

      command line    : m002 5 20 7
      expected output : 5 7 20

   Directions:

      Please, edit function sort();
      do no not change function main().

 */


#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

#define USAGE "m002 <num1> <num2> <num3>\n"

/* Sort three integers x, y, z in ascending order.*/
void sort(int *a, int *b, int *c)
{
  /*variavel provisoria para receber o valor pre inversao*/
  int k;

  /*inverter o primeiro e o segundo valores recebidos
  caso o primeiro seja maior que o segundo*/
  if(*a > *b) {
    k = *b;
    *b = *a;
    *a = k;
  }

  /*inverter o primeiro e o terceiro valores recebidos
  caso o primeiro seja maior que o terceiro*/
  if(*a > *c) {
    k = *c;
    *c = *a;
    *a = k;
  } 

  /*inverter o segundo e o terceiro valores recebidos 
  caso o segundo seja maior que o terceiro*/
  if(*b > *c) {
    k = *c;
    *c = *b;
    *b = k;
  }
}

/* Do not edit this function. */
int main (int argc, char **argv)
{
  int a, b, c;

  if (argc < 4)
    {
      printf (USAGE);
      exit(1);
    }

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);
  
  sort (&a, &b, &c);

  printf ("%d %d %d\n", a, b, c);
  
  return 0;
}
